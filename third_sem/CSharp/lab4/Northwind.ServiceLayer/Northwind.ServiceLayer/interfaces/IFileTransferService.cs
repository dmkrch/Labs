
namespace Northwind.ServiceLayer.interfaces
{
    public interface IFileTransferService
    {
        public void TransferFiles(string xmlFileName, string xsdFileName, string sourceDirectoryPath, string targetDirectoryPath);
    }
}
