using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Form1
{
    public partial class FormInput : Form
    {
        public int X { get; set; }
        public int Y { get; set; }

        public FormInput()
        {
            InitializeComponent();
            X = 0;
            Y = 0;
        }

        private void FormInput_Load(object sender, EventArgs e)
        {

        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;

            X = Convert.ToInt16(this.textBoxX.Text);
            Y = Convert.ToInt16(this.textBoxY.Text);
        }
    }
}
