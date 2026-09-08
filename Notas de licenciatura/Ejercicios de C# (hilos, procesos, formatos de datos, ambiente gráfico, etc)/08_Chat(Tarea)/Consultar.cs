using Newtonsoft.Json;
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
    public partial class Consultar : Form
    {
        public Consultar()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void Consultar_Load(object sender, EventArgs e)
        {
            String url = "http://serviciosdigitalesplus.com/chat/?tipo=2&usuario=201927821"; // CAMBIAR DE MATRICULAAAAA
            String texto = (new WebClient().DownloadString(url));
            Root r = JsonConvert.DeserializeObject<Root>(texto);
            for (int i = 0; i < r.chat.Count; i++)
            {
                
                this.dataGridView1.Rows.Add();
                this.dataGridView1.Rows[i].Cells[0].Value = r.chat[i].cliente;
                this.dataGridView1.Rows[i].Cells[1].Value = r.chat[i].fecha;
                this.dataGridView1.Rows[i].Cells[2].Value = r.chat[i].descripcion;

            }
        }
    }

    

}
