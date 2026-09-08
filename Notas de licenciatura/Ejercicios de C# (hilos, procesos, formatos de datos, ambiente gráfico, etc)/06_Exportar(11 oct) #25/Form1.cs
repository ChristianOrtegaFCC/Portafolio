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

namespace _06_Exportar_11_Oct_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exportarExcelToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "Excel (*.xls)|.xls";

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String archivo = saveFileDialog1.FileName;
                StreamWriter sw = new StreamWriter(archivo,false);
                sw.WriteLine(ConvertoExcel());
                sw.Close();
            }
            ConvertoExcel();
        }

        public String ConvertoExcel()
        {
            String line = "<table>";
            line += "<tr>";
            line += "<th>";
            line += "<ID>";
            line += "</th>";
            line += "<th>";
            line += "<Nombre>";
            line += "</th>";
            line += "</tr>";

            for (int i = 0; i < dataGridView1.Rows.Count - 1; i++)
            {
                line += "<tr>";
                line += "<td>";
                line += dataGridView1.Rows[i].Cells[0].Value.ToString();
                line += "</td>";
                line += "<td>";
                line += dataGridView1.Rows[i].Cells[1].Value.ToString();
                line += "</td>";
                line += "</tr>";
            }
            line += "</table>";
            return line;
        }
    }
}
