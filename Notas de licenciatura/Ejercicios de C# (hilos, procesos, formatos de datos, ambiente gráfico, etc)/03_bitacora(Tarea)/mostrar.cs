using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _03_bitacora
{
    public partial class mostrar : Form
    {
        public mostrar()
        {
            InitializeComponent();
        }

        private void mostrar_Load(object sender, EventArgs e)
        {
            String direccion = Path.GetFullPath("bitacora.txt");
            if (File.Exists(direccion))
            {
                StreamReader sr = new StreamReader(direccion);
                String linea = "";
                while ((linea = sr.ReadLine()) != null)
                {
                    String[] arr = linea.Split('@');
                    //dataGridView1.Rows[i].Cells[0].Value.ToString();
                    int i = this.dataGridView1.Rows.Add();
                    this.dataGridView1.Rows[i].Cells[0].Value = arr[0];
                    this.dataGridView1.Rows[i].Cells[1].Value = arr[1];

                }
                sr.Close();
            }
        }
    }
}
