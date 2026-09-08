using System.Drawing.Text;
using System.Text.RegularExpressions;

namespace wordNuevo
{
    public partial class Form1 : Form
    {
        String archivo;
        String notificacion;
        Form2 acerca;
        
        public Form1()
        {
            InitializeComponent();
            archivo = "";
            notificacion = "";
            toolStripStatusLabel1.Text = "Bienvenido";

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            toolStripComboBox2.Items.Add(8);
            toolStripComboBox2.Items.Add(9);
            toolStripComboBox2.Items.Add(10);
            toolStripComboBox2.Items.Add(11);
            toolStripComboBox2.Items.Add(12);
            toolStripComboBox2.Items.Add(14);
            toolStripComboBox2.Items.Add(16);
            toolStripComboBox2.Items.Add(18);
            toolStripComboBox2.Items.Add(20);
            toolStripComboBox2.Items.Add(22);
            toolStripComboBox2.Items.Add(24);
            toolStripComboBox2.Items.Add(26);
            toolStripComboBox2.Items.Add(28);
            toolStripComboBox2.Items.Add(36);
            toolStripComboBox2.Items.Add(48);
            toolStripComboBox2.Items.Add(72);
            
            InstalledFontCollection ifc = new InstalledFontCollection();
            FontFamily[] familia = ifc.Families;
            for (int i = 0; i < ifc.Families.Length; i++)
            {
                toolStripComboBox1.Items.Add(ifc.Families[i].Name);
            }

            toolStripComboBox1.SelectedIndex = 41;
            toolStripComboBox2.SelectedIndex = 0;

        }

        private void principalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip1.Visible = !toolStrip1.Visible;
        }

        private void parrafoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip2.Visible = !toolStrip2.Visible;
        }

        private void imagenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip3.Visible = !toolStrip3.Visible;
        }

        private void toolStripButton6_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                toolStripButton6.BackColor = colorDialog1.Color;
                richTextBox1.SelectionColor = colorDialog1.Color;
            }
        }

        private void toolStripComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            fuente();
        }

        private void toolStripComboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            fuente();
        }

        public void fuente()
        {
            float aux = toolStripComboBox2.Text == ""? 8: float.Parse(toolStripComboBox2.Text);
            richTextBox1.SelectionFont = new Font(toolStripComboBox1.Text, aux);
            richTextBox1.Focus();
        }

        private void toolStripButton7_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Left;
        }

        private void toolStripButton8_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Center;
        }

        private void toolStripButton9_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Right;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            guardar();
        }

        public void guardar()
        {
            SaveFileDialog gArch = new SaveFileDialog();
            gArch.DefaultExt = "*.buap";
            gArch.Filter = "BUAP Files|*.buap";

            if (gArch.ShowDialog() == DialogResult.OK)
            {
                archivo = gArch.FileName;
                richTextBox1.SaveFile(gArch.FileName, RichTextBoxStreamType.RichText);
                toolStripStatusLabel1.Text = "Guardando...";
                notificacion = "El archivo se ha guardado correctamente";
                toolStripProgressBar1.Visible = true;
                timer1.Start();
                
            }

        }

        public void abrir()
        {
            OpenFileDialog aArch = new OpenFileDialog();
            aArch.DefaultExt = "*.buap";
            aArch.Filter = "BUAP Files|*.buap";

            if (aArch.ShowDialog() == DialogResult.OK)
            {
                archivo = aArch.FileName;
                richTextBox1.LoadFile(aArch.FileName);
                toolStripStatusLabel1.Text = "Abriendo...";
                notificacion = "El archivo se ha abierto correctamente";
                toolStripProgressBar1.Visible = true;
                timer1.Start();
                
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            abrir();
        }

        private void guardarComoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            guardar();
        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            abrir();
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (archivo== "")
            {
                guardar();
            }
            else
            {
                richTextBox1.SaveFile(archivo, RichTextBoxStreamType.RichText);
                toolStripStatusLabel1.Text = "Guardando...";
                notificacion = "El archivo se ha guardado correctamente";
                toolStripProgressBar1.Visible = true;
                timer1.Start();
                
            }
        }

        private void toolStripButton10_Click(object sender, EventArgs e)
        {
            agregarImagen();
        }

        public void agregarImagen()
        {
            OpenFileDialog iArch = new OpenFileDialog();

            iArch.DefaultExt = "*.jpg";
            iArch.Filter = "Image Files|*.jpg";

            if (iArch.ShowDialog() == DialogResult.OK)
            {
                Bitmap imagen = new Bitmap(iArch.FileName);
                Clipboard.SetDataObject(imagen);
                DataFormats.Format formato = DataFormats.GetFormat(DataFormats.Bitmap);
                richTextBox1.Paste(formato);
                toolStripStatusLabel1.Text = "Cargando...";
                notificacion = "La imagen se ha cargado correctamente";
                toolStripProgressBar1.Visible = true;
                timer1.Start();
                
            }
        }

        private void imagenToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            agregarImagen();
        }

        public void negrita()
        {
            if (richTextBox1.SelectionFont != null)
            {
                if (richTextBox1.SelectionFont.Bold == true)
                {
                    normal();
                }
                else
                {
                    richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size, FontStyle.Bold);
                }
            }
            
            richTextBox1.Focus();
        }

        public void cursiva()
        {
            if (richTextBox1.SelectionFont != null)
            {
                if (richTextBox1.SelectionFont.Italic == true)
                {
                    normal();
                }
                else
                {
                    richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size, FontStyle.Italic);
                }
            }

            richTextBox1.Focus();
        }

        public void subrayado()
        {
            if (richTextBox1.SelectionFont != null)
            {
                if (richTextBox1.SelectionFont.Underline == true)
                {
                    normal();
                }
                else
                {
                    richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size, FontStyle.Underline);
                }
            }

            richTextBox1.Focus();
        }

        public void normal()
        {
            if (richTextBox1.SelectionFont != null)
            {
                richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, richTextBox1.SelectionFont.Size, FontStyle.Regular);
            }

            richTextBox1.Focus();
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            negrita();
        }

        private void nuevoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            archivo = "";
            toolStripStatusLabel1.Text = "Creando nuevo archivo...";
            notificacion = "El archivo se ha creado correctamente";
            toolStripProgressBar1.Visible = true;
            timer1.Start();
            
        }

        private void toolStripButton13_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            toolStripStatusLabel1.Text = "Borrando...";
            notificacion = "Se ha borrado pantalla correctamente";
            toolStripProgressBar1.Visible = true;
            timer1.Start();
           
        }

        private void toolStripButton14_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectionFont != null)
            {
                richTextBox1.SelectionFont = new Font(richTextBox1.SelectionFont.FontFamily, 8, FontStyle.Regular);
                richTextBox1.SelectionColor = Color.Black;
            }

            richTextBox1.Focus();
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            cursiva();
        }

        private void toolStripButton12_Click(object sender, EventArgs e)
        {
            if (richTextBox1.CanRedo == true)
            {
                    richTextBox1.Redo();
            }
        }

        private void toolStripButton5_Click(object sender, EventArgs e)
        {
            subrayado();
        }

        private void toolStripButton11_Click(object sender, EventArgs e)
        {
            if (richTextBox1.CanUndo == true)
            {
                richTextBox1.Undo();
            }
        }

        private void blodToolStripMenuItem_Click(object sender, EventArgs e)
        {
            negrita();
        }

        private void italicToolStripMenuItem_Click(object sender, EventArgs e)
        {
            cursiva();
        }

        private void subrayadoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            subrayado();
        }

        private void alinearIzqToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Left;
        }

        private void alinearCentroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Center;
        }

        private void alinearDerechaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectionAlignment = HorizontalAlignment.Right;
        }

        private void acercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (acerca == null)
            {
                acerca = new Form2();
                acerca.ShowDialog();
            }
            else
            {
                acerca.ShowDialog();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
            int auxiliar = 0;
            toolStripProgressBar1.Increment(5);

            if (toolStripProgressBar1.Value == 100)
            {
                if (toolStripProgressBar1.Value == 100 && auxiliar == 0)
                {
                    auxiliar = 1;
                }
                timer1.Stop();
                toolStripProgressBar1.Value = 0;

            }

            //Esto se puso ya que habia un bug que se seguia a mas de 100 el timer y con esto nos aseguramos que si llego a 100 solo se muestre una vez esta ventana
            if (auxiliar == 1)
            {
                MessageBox.Show(notificacion, "Notificacion");
                notificacion = "";
                toolStripProgressBar1.Visible = false;
                toolStripStatusLabel1.Text = "Editando archivo " + archivo;
            }

        }

        private void acercaDeToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            
            Form2 acerca = new Form2();
            acerca.Show();

        }
    }
}