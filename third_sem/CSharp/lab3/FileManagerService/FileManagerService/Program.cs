using System;
using System.ServiceProcess;

namespace FileManagerService
{
    static class Program
    {
        static void Main(string[] args)
        {
            if (Environment.UserInteractive)
            {
                Service1 service1 = new Service1();
                service1.TestStartupAndStop(args);
            }
            else
            {
                ServiceBase[] ServicesToRun;
                ServicesToRun = new ServiceBase[]
                {
                new Service1()
                };
                ServiceBase.Run(ServicesToRun);
            }
        }
    }
}
