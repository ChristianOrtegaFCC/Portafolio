using System;
using SautinSoft.Document;

namespace word_rtf
{
    class program
    {
        static void Main(string[] args)
        {
            try
            {

                Console.Write("Nombre del documento .docx que quieres convertir a .rtf: ");
                String nombre = Console.ReadLine();
                DocumentCore dc = DocumentCore.Load(nombre + ".docx");
                dc.Save(nombre + ".rtf");
                Console.WriteLine("Listo! :)");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
