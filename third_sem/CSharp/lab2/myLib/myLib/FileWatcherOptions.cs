using System;
using System.Collections.Generic;
using System.Text;

namespace myLib
{
    /* contains all the options that logger needs */
    [Serializable]
    public class FileWatcherOptions
    {
        public PathsOptions PathsOptions { get; set; }
        public EncryptingOptions EncryptingOptions { get; set; }
        public CompressOptions CompressOptions { get; set; }

        public FileWatcherOptions()
        {
            this.PathsOptions = new PathsOptions();
            this.EncryptingOptions = new EncryptingOptions();
            this.CompressOptions = new CompressOptions();
        }
    }


    /* contains paths of source directory and target directory of files */
    [Serializable]
    public class PathsOptions
    {
        public string ClientDirectory { get; set; }
        public string TargetDirectory { get; set; }
    }


    /* contains key of encrypting and decrypting data */ 
    [Serializable]
    public class EncryptingOptions
    {
        public string Key { get; set; }
    }

    
    /* contains format of compression we want to do */
    [Serializable]
    public class CompressOptions
    {
        public string CompressFormat { get; set; }
    }

}
