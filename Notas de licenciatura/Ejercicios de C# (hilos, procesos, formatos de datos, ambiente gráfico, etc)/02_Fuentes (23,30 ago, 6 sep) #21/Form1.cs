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
using System.Xml.Linq;

namespace _03_Fuentes
{
    public partial class Form1 : Form
    {
        String Documento;
        int estados;
        String Direccion;
        Acerca acerca;
        Opciones op;

        public Form1()
        {
            InitializeComponent();
        }

        private void acercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (acerca == null)
            {
                acerca = new Acerca();
                acerca.ShowDialog();
            }
            else
            {
                acerca.ShowDialog();
            }
        }

        private void opcionesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (op == null)
            {
                op = new Opciones(this);
                op.ShowDialog();
            }
            else
            {
                op.ShowDialog();
            }
        }

        public void colorTexto(Color c)
        {

        }

        public void newColor(int red, int green, int blue)
        {
            Color c = Color.FromArgb(red, green, blue);
            richTextBox1.ForeColor = c;
        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {

        }

        public void notificacion(String line)
        {
            this.toolStripStatusLabel1.Text = line;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            loadColor();
            loadFuente();
            Documento = "";
            Direccion = "";
        }

        public void loadColor()
        {
            String archivo = Path.GetFullPath("color.txt");
            if (File.Exists(archivo))
            {
                StreamReader sr = new StreamReader(archivo);
                String Scolor = sr.ReadToEnd();
                sr.Close();
                String[] rgb = Scolor.Split(';');

                int r = Convert.ToInt32(rgb[0]);
                int g = Convert.ToInt32(rgb[1]);
                int b = Convert.ToInt32(rgb[2]);
                newColor(r, g, b);

            }
        }

        public void loadFuente()
        {
            String archivo = Path.GetFullPath("fuente.data");
            if (File.Exists(archivo))
            {
                StreamReader sr = new StreamReader(archivo);
                String miFuente = sr.ReadToEnd();
                sr.Close();
                String[] fuenteArr = miFuente.Split(';');
                fuente(fuenteArr[0], float.Parse( fuenteArr[1]), ConvertFontStyle(Convert.ToInt32(fuenteArr[2])));
            }
        }

        public FontStyle ConvertFontStyle(int id)
        {
            if (id == 1)
            {
                return FontStyle.Bold;
            }
            else if (id == 2)
            {
                return FontStyle.Italic;
            }
            else if (id == 8)
            {
                return FontStyle.Strikeout;
            }
            else if (id == 4)
            {
                return FontStyle.Underline;
            }
            else
            {
                return FontStyle.Regular;
            }
        }

        public void fuente(Font fuente1)
        {
            richTextBox1.Font = fuente1;
        }

        public void fuente(String name, float size, FontStyle Style)
        {
            richTextBox1.Font = new Font(name,size, Style);
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String cadena = richTextBox1.Text;
            if (Documento == cadena)
            {
                Application.Exit();
            }
            else
            {
                String message = "Quieres guardar los cambios en?";
                String titulo = "Close Windows";
                MessageBoxButtons btn = MessageBoxButtons.YesNo;
                DialogResult result = MessageBox.Show(message, titulo, btn);
                if (result == DialogResult.Yes)
                {
                    guardarSimple();
                    Application.Exit();
                }
                else
                {
                    Application.Exit();
                }
            }
            
        }

        private void nuevoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            estados = 1;
            Documento = "";
            Direccion = "";
            richTextBox1.Text = "";
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            guardarSimple();
        }

        public void guardarSimple()
        {
            estados = 3;
            if (Direccion != "")
            {
                String linea = Path.GetFullPath(Direccion);
                StreamWriter sw = new StreamWriter(linea, false);
                sw.Write(richTextBox1.Text);
                Documento = richTextBox1.Text;
                sw.Close();
            }
            else
            {
                guardarDocumento();
            }
        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            estados = 2;
            openFileDialog1.FileName = "Seleccione el archivo";
            openFileDialog1.Filter = "Text files (*.txt) | *.txt";
            openFileDialog1.Title = "Abrir archivo";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String url = openFileDialog1.FileName;
                Direccion = url;
                StreamReader sr = new StreamReader(url);
                String texto = sr.ReadToEnd();
                sr.Close();
                richTextBox1.Text = texto;
                Documento = texto;
            }
        }

        private void guardarComoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            estados = 4;
            guardarDocumento();

        }

        public void guardarDocumento()
        {
            saveFileDialog1.Filter = "Text files (*.txt) | *.txt";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String fichero = saveFileDialog1.FileName;
                Direccion = fichero;
                String linea = Path.GetFullPath(fichero);
                StreamWriter sw = new StreamWriter(linea, false);
                sw.Write(richTextBox1.Text);
                Documento = richTextBox1.Text;
                sw.Close();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (Documento != richTextBox1.Text)
            {
                String message = "Quieres guardar los cambios en?";
                String titulo = "Close Windows";
                MessageBoxButtons btn = MessageBoxButtons.YesNo;
                DialogResult result = MessageBox.Show(message, titulo, btn);
                if (result == DialogResult.Yes)
                {
                    guardarSimple();
                    Application.Exit();
                }
                else
                {
                    Application.Exit();
                }
            }
        }
    }
}
