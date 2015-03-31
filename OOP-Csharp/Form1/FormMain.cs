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
    public partial class FormMain : Form
    {
        //Detta funkar, man kan ha samma namn. private FormInput FormInput = new FormInput();
        private FormInput formInput = new FormInput();
        private int x = 200;
        private int y = 200;
        public FormMain()
        {
            InitializeComponent();
        }

        private Pen pen = new Pen(Brushes.Black);

        private void FormMain_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Rectangle r = new Rectangle(x, y, 50, 100);
            
            g.DrawBezier(pen, new Point(100, 100), new Point(150, 150), new Point(200, 50), new Point(300, 100));
            g.DrawRectangle(pen, r);
        }

        private void FormMain_MouseClick(object sender, MouseEventArgs e)
        {
            this.x = e.X;
            this.y = e.Y;
            this.Invalidate(); //Tvingar hela fönstret att ritas om med event Paint
        }

        private void FormMain_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left || e.KeyCode == Keys.A)
                this.x -= 10;
            else if (e.KeyCode == Keys.Right || e.KeyCode == Keys.D)
                this.x += 10;
            else if (e.KeyCode == Keys.Up || e.KeyCode == Keys.W)
                this.y -= 10;
            else if (e.KeyCode == Keys.Down || e.KeyCode == Keys.S)
                this.y -= -10;

            this.Invalidate();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {

        }

        private void toolStripContainer1_LeftToolStripPanel_Click(object sender, EventArgs e)
        {

        }

        private void inputToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void ändraPositionToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.formInput.ShowDialog(this) == DialogResult.OK)
            {
                this.x = formInput.X;
                this.x = formInput.X;
                this.Invalidate();
            }

        }

        private void ändraBakgrundsfärgToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.menuStrip1.BackColor = System.Drawing.SystemColors.ButtonFace;
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {
            this.BackColor = System.Drawing.SystemColors.MenuHighlight;
            this.menuStrip1.BackColor = System.Drawing.SystemColors.MenuHighlight;
        }

        private void toolStripMenuItem3_Click(object sender, EventArgs e)
        {
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.menuStrip1.BackColor = System.Drawing.SystemColors.ActiveBorder;
        }
    }
}
