using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Northwind.DataManagerService
{
    /* contains all the options that logger needs */
    [Serializable]
    public class DataManagerOptions
    {
        public PathsOptions PathsOptions { get; set; }

        public DataManagerOptions()
        {
            this.PathsOptions = new PathsOptions();
        }
    }

    /* contains paths of source directory and target directory of files */
    [Serializable]
    public class PathsOptions
    {
        public string DestinationDirectory { get; set; }        // I DIDNT ADD TO XML AND XSD FILE!
        public string DBpath1 { get; set; }                 // I DIDNT ADD TO XML AND XSD FILE!
        public string DBpath2 { get; set; }                 // I DIDNT ADD TO XML AND XSD FILE!
    }
}
