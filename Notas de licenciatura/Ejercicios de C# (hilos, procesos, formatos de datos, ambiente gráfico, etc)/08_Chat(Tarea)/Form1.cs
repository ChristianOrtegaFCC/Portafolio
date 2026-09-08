using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.Net;

namespace _08_Chat_Tarea_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void consultarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Consultar C = new Consultar();
            C.Show();
        }

        private void crearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Crear C = new Crear();
            C.Show();
        }
    }

    public class Chat
    {
        public string cliente { get; set; }
        public string usuario { get; set; }
        public string descripcion { get; set; }
        public string fecha { get; set; }

    }

    public class Root
    {
        public List<Chat> chat { get; set; }
    }

}