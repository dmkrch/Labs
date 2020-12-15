using Northwind.ServiceLayer.interfaces;
using System;
using System.IO;

namespace Northwind.ServiceLayer.implementations
{
    public class XmlandXsdFileTransfer : IFileTransferService
    {
        public void TransferFiles(string xmlFileName, string xsdFileName, string sourceDirectoryPath, string targetDirectoryPath)
        {
            try
            {
                string str = DateTime.Now.ToString();
                str = str.Replace(' ', '_');
                str = str.Replace('.', '_');
                str = str.Replace(':', '_');
                var k = '.';
                var i = xmlFileName.Length - 1;
                while (k != xmlFileName[i])
                    i--;

                string file = xmlFileName.Insert(i, str);
                FileInfo file1 = new FileInfo(Path.Combine(sourceDirectoryPath, xmlFileName));
                file1.MoveTo(Path.Combine(targetDirectoryPath, file));
                FileInfo file2 = new FileInfo(Path.Combine(sourceDirectoryPath, xsdFileName));
                file2.MoveTo(Path.Combine(targetDirectoryPath, xsdFileName));

            }
            catch (Exception e)
            {
                //IErLogger logger = new Logger();
                //logger.WriteError(e);
            }
        }
    }
}
