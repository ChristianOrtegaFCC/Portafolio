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
    public partial class buscar : Form
    {
        public buscar()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)// aqui va para buscar datos de una fecha
        {
            this.dataGridView1.Rows.Clear();// borramos consultas anteriores, en caso de que las haya

            String buscar = dateTimePicker1.Value.ToString(); // obtenemos la fecha del dateTimePicker1
            string[] partes = buscar.Split(' '); // le quitamos la hora
            buscar = partes[0]; // guardamos la fecha limpia aquí

            String direccion = Path.GetFullPath("bitacora.txt");
            if (File.Exists(direccion))
            {
                StreamReader sr = new StreamReader(direccion);
                String linea = "";
                while ((linea = sr.ReadLine()) != null) // leemos una linea del archivo de texto
                {
                    String[] arr = linea.Split('@'); // separamos esa linea en nombres y fechas
                    String[] arraux = arr[1].Split(' ');//separamos el valor de la fecha que nos importa (quitamos la hora)
                    if (arraux[0] == buscar) { // comparamos la fecha de la línea leída con la fecha que queremos mostrar
                        // caso verdadero, escribimos en el dataGridView1:
                        int i = this.dataGridView1.Rows.Add();
                        this.dataGridView1.Rows[i].Cells[0].Value = arr[0]; // nombre
                        this.dataGridView1.Rows[i].Cells[1].Value = arr[1]; // fecha
                    }
                }
                sr.Close();
            }
        }
    }
}
