using ConfigurationManager;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using Northwind.DataAccessLayer.Repository.implementations;
using FileManager;
using Northwind.ServiceLayer.implementations;
using Northwind.Models;
using MyConfigurationManager;

namespace Northwind.DataManager
{
    public partial class Service1 : ServiceBase
    {
        public Service1()
        {
            InitializeComponent();
        }

        protected override void OnStart(string[] args)
        {
            /* when we start our service we are generating xml files according to data from database */
            var projectPath = AppDomain.CurrentDomain.BaseDirectory;
            var manager = new MyConfigurationManager.ConfigurationManager();
            var pathOption = manager.GetOptions<PathsOptions>(projectPath + "xmlConfig.xml");

            try
            {
                var repositories = new UnitOfWork(pathOption.DBpath1);
                OrderService orderService = new OrderService(repositories);

                /* now getting list of orders */
                var ordersInfo = orderService.GetListOfOrders();

                XmlGenerateService<Order> orders = new XmlGenerateService<Order>(pathOption.ClientDirectory + "\\Orders.xml");

                /* generating xml file */
                orders.XmlGenerate(ordersInfo);
            }

            catch (Exception trouble)
            {
                /* if something went wrong */
                var repositories2 = new UnitOfWork(pathOption.DBpath2);
                ErrorService service = new ErrorService(repositories2);
                service.AddErrors(new Errors(trouble.GetType().Name, trouble.Message, DateTime.Now));
            }
        }

        protected override void OnStop()
        {
            /* not implemented */
        }
    }
}
