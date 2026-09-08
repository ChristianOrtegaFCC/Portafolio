using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _08_Chat_Tarea_
{
    public partial class Crear : Form
    {
        public Crear()
        {
            InitializeComponent();
        }

        private void Crear_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.textBox1.Text == "" || this.textBox2.Text == "")
            {
                MessageBox.Show("Debes llenar ambos campos para continuar...");
                return;
            }
            else
            {
                String cliente = "";
                String usuario = "201927821";   // CAMBIAR DE MATRICULAAAAA
                String descripcion = "";

                cliente = this.textBox1.Text;
                descripcion = this.textBox2.Text;

                String url = "http://serviciosdigitalesplus.com/chat/?tipo=1&cliente="
                    + cliente + "&descripcion=" + descripcion + "&usuario=" + usuario;
                String texto = (new WebClient().DownloadString(url));

                MessageBox.Show("Mensaje enviado");
            }
        }
    }
}
