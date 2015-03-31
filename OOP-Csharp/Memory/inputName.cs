using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Memory
{
    public partial class inputName : Form
    {
        public string NAME { get; set; }
        public inputName()
        {
            InitializeComponent();
            textBox1.Focus();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                NAME = textBox1.Text;
                this.Close();
            }
            else
                MessageBox.Show("Ange namn", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {

            if (e.KeyCode == Keys.Enter)
            {
                if (textBox1.Text != "")
                {
                    NAME = textBox1.Text;
                    this.Close();
                }
                else
                    MessageBox.Show("Ange namn", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void inputName_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("Ange namn","Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                e.Cancel = true;
            }
            
        }

        private void inputName_Load(object sender, EventArgs e)
        {
            textBox1.Focus();
        }

    }
}
