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
    public partial class procesos : UserControl
    {
        
        public int tamaño = 0;
        public int incremento = 0;
        public int con = 0;

        public procesos()
        {
            InitializeComponent();
            label3.Text = "";
        }

        private void procesos_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            tamaño = Convert.ToInt32(textBox2.Text);
            incremento = Convert.ToInt32(textBox1.Text);

            progressBar1.Maximum = tamaño;
            timer1.Start();
            this.button1.Text = "Run";
            button1.Enabled = false;
            progressBar1.Step = incremento;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            con = con + incremento;

            if (con <= tamaño)
            {
                progressBar1.Value = con;
            }
            else
            {
                con = 0;
                progressBar1.Value = 0;
                timer1.Stop();
                button1.Text = "Start";
                button1.Enabled = true;
            }
        }

        private void textBox1_KeyUp(object sender, KeyEventArgs e)
        {
            try
            {
                int i = Convert.ToInt32(textBox1.Text);
            }
            catch (Exception ex)
            {
                textBox1.Text = "";
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

        public void titulo(String cadena)
        {
            label3.Text = "proceso: "+cadena;
        }

    }
}
