using ConfigurationManager;
using ConfigurationManager.Parsers.parsers;
using FileManagerService;
using Northwind.DataAccessLayer.Repository.implementations;
using Northwind.Models;
using Northwind.ServiceLayer.implementations;
using System;
using System.IO;
using System.ServiceProcess;
using System.Threading;

namespace Northwind.DataManagerService
{
    public partial class Service1 : ServiceBase
    { 
        DataManagerOptions options = new DataManagerOptions();


        public Service1()
        {
            /* setting parser and options of DataManager to variable 'options' */

            string xmlConfigurationFileName = @"D:\Programming\Labs\third_sem\CSharp\lab5\configs\DataManagerConfig.xml";

            if (File.Exists(xmlConfigurationFileName))
            {
                XmlParser parser = new XmlParser();

                /* adding xml parser to configuration manager */
                ConfigManager configurationManager = new ConfigManager(parser);


                options.PathsOptions = configurationManager.GetOptions<PathsOptions>(xmlConfigurationFileName);
            }
            else
            {
                throw new IOException("Configuration file with incorrect extension");
            }

            InitializeComponent();
        }

        internal void TestStartupAndStop(string[] args)
        {
            this.OnStart(args);
            Console.ReadLine();
            this.OnStop();
        }

        protected override void OnStart(string[] args)
        {
            ThreadPool.QueueUserWorkItem(async state =>
            {
                try
                {
                    var repositories = new UnitOfWork(options.PathsOptions.DBpath1);
                    OrderService orderService = new OrderService(repositories);

                    /* now getting list of orders */
                    var ordersList = await orderService.GetListOfOrders();

                    /* now we need to make a file name */
                    string fileName = options.PathsOptions.DestinationDirectory;
                    fileName += @"\Orders_";

                    DateTime now = DateTime.Now;
                    var currTime = now.ToString("yyyy_MM_dd_HH_mm_ss");
                    fileName += currTime;

                    /* file name almost ready. now we create xmlgenerator instance and pass the xml path */
                    XmlGenerateService<Order> orders = new XmlGenerateService<Order>(fileName + ".xml");

                    /* now we generating xml file with orders */
                    await orders.XmlGenerate(ordersList);

                    this.OnStop();
                }
                catch (Exception trouble)
                {
                    /* if something went wrong */
                    var repositories2 = new UnitOfWork(options.PathsOptions.DBpath2);
                    ErrorService service = new ErrorService(repositories2);
                    service.AddErrors(new Error(trouble.GetType().Name, trouble.Message, DateTime.Now));
                }
            });
        }

        protected override void OnStop()
        {
            Thread.Sleep(1000);
        }
    }
}
