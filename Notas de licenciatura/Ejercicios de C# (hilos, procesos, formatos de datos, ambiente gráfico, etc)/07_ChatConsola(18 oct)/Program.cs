using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.Net;

namespace chatConsola2
{
    class Program
    {
        static void Main(string[] args)
        {
            String opcion = "";
            while (true)
            {
                //Console.Clear();
                Console.WriteLine("  -------  Menu  -------");
                Console.WriteLine("   1.- Consultar");
                Console.WriteLine("   2.- Crear");
                Console.Write("   x.- Salir\n    >> ");
                opcion = Console.ReadLine();
                if (opcion == "1")
                {
                    String url = "http://serviciosdigitalesplus.com/chat/?tipo=2&usuario=123";
                    String texto = (new WebClient().DownloadString(url));
                    Root r = JsonConvert.DeserializeObject<Root>(texto);
                    for (int i = 0;i<r.chat.Count;i++)
                    {
                        Console.WriteLine(r.chat[i].cliente + "\t"+ r.chat[i].fecha+ "\t" + r.chat[i].descripcion);
                    }
                }
                else if (opcion == "2")
                {
                    String cliente = "";
                    String usuario = "123";
                    String descripcion = "";

                    Console.WriteLine("Da el nombre del cliente: ");
                    cliente = Console.ReadLine();
                    Console.WriteLine("Da el mensaje: ");
                    descripcion = Console.ReadLine();

                    String url = "http://serviciosdigitalesplus.com/chat/?tipo=1&cliente="
                        + cliente+"&descripcion="+descripcion+"&usuario="+ usuario;
                    String texto = (new WebClient().DownloadString(url));


                }
                else if (opcion == "x")
                {
                    break;
                }
                else
                {
                    Console.WriteLine("   Opcion no valida\n");
                }



            }
        }
    }

    public class Chat
    {
        public string cliente {get; set;}
        public string usuario {get; set;}
        public string descripcion { get; set; }
        public string fecha { get; set; }

    }

public class Root
    {
        public List<Chat> chat { get; set; }
    }
}
