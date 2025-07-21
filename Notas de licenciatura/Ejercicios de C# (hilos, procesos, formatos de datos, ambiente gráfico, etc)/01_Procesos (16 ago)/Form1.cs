using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace codigo2
{
    public partial class Form1 : Form
    {
        private procesos[] proc1;
        int i = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            int t;
            try
            {
                t = Convert.ToInt32(textBox2.Text);
                proc1 = new procesos[t];
            }
            catch (Exception ex)
            {
                t = 1;
            }

            int y = 40;
            int incremento = 150;

            for(int i = 0; i < t; i++)
            {
                proc1[i] = new procesos();
                proc1[i].Location = new System.Drawing.Point(12,y);
                proc1[i].Name = "Procesos " + i;
                proc1[i].Size = new System.Drawing.Size(175,156);
                proc1[i].titulo((i+1).ToString());
                y = y + incremento;
                this.Controls.Add(proc1[i]);
            }
        }

        private void textBox2_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                int i = Convert.ToInt32(textBox2.Text);
            }
            catch (Exception ex)
            {
                textBox2.Text = "";
            }
        }
    }
}
