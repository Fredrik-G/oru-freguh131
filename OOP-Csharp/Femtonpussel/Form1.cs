using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Femtonpussel
{
    public partial class FormPussel : Form
    {
        private void RitaIkoner()
        {//Funktion som ritar ut random ikon i rutorna.

            List<string> ikoner = new List<string>() 
            {//Lista med bokstäver som kommer representera ikoner i programmet.
                "", "1",  "2", "3", "4", "5", "6", "7", "8",
                "9", "10", "11", "12", "13", "14", "15"
            };

            Random random = new Random();
            foreach (Control control in tableLayoutPanel1.Controls)
            {//Går igenom alla labels/ikoner i programmet.
                Label ikonText = control as Label;
                if (ikonText != null)
                {//Slumpar fram en random bokstav ur listan och tar sedan bort den.
                    int randomNumber = random.Next(ikoner.Count);
                    ikonText.Text = ikoner[randomNumber];
                    ikoner.RemoveAt(randomNumber);
                }
            }
        }

        public FormPussel()
        {
            InitializeComponent();
            RitaIkoner();
        }
        private void Move(Label labelClicked)
        {
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label labelZero = control as Label;

                if (labelZero.Text == "")
                {
                    labelZero.Text = labelClicked.Text;
                    labelClicked.Text = "";
                    break;
                }
            }
        }

        #region Click&Move
        private void label1_Click(object sender, EventArgs e)
        {
            if (label2.Text == "" || label5.Text == "")
                Move(label1);
        }

        private void label2_Click(object sender, EventArgs e)
        {
            if (label1.Text == "" || label3.Text == "" || label6.Text == "")
                Move(label2);
        }
        private void label3_Click(object sender, EventArgs e)
        {
            if (label2.Text == "" || label4.Text == "" || label7.Text == "")
                Move(label3);
        }

        private void label4_Click(object sender, EventArgs e)
        {
            if (label3.Text == "" || label8.Text == "")
                Move(label4);
        }

        private void label5_Click(object sender, EventArgs e)
        {
            if (label1.Text == "" || label6.Text == "" || label9.Text == "")
                Move(label5);
        }

        private void label6_Click(object sender, EventArgs e)
        {
            if (label2.Text == "" || label5.Text == "" || label7.Text == "" || label10.Text == "")
                Move(label6);
        }
        private void label7_Click(object sender, EventArgs e)
        {
            if (label3.Text == "" || label6.Text == "" || label8.Text == "" || label11.Text == "")
                Move(label7);
        }

        private void label8_Click(object sender, EventArgs e)
        {
            if (label4.Text == "" || label7.Text == "" || label12.Text == "")
                Move(label8);
        }

        private void label9_Click(object sender, EventArgs e)
        {
            if (label5.Text == "" || label10.Text == "" || label16.Text == "")
                Move(label9);
        }

        private void label10_Click(object sender, EventArgs e)
        {
            if (label6.Text == "" || label9.Text == "" || label11.Text == "" || label13.Text == "")
                Move(label10);
        }

        private void label11_Click(object sender, EventArgs e)
        {
            if (label7.Text == "" || label10.Text == "" || label12.Text == "" || label14.Text == "")
                Move(label11);
        }

        private void label12_Click(object sender, EventArgs e)
        {
            if (label8.Text == "" || label11.Text == "" || label15.Text == "")
                Move(label12);
        }

        private void label16_Click(object sender, EventArgs e)
        {
            if (label9.Text == "" || label13.Text == "")
                Move(label16);
        }

        private void label13_Click(object sender, EventArgs e)
        {
            if (label10.Text == "" || label16.Text == "" || label14.Text == "")
                Move(label13);
        }

        private void label14_Click(object sender, EventArgs e)
        {
            if (label11.Text == "" || label13.Text == "" || label15.Text == "")
                Move(label14);
        }

        private void label15_Click(object sender, EventArgs e)
        {
            if (label12.Text == "" || label14.Text == "")
                Move(label15);
        }
        #endregion

        private void FormPussel_KeyDown(object sender, KeyEventArgs e)
        /*    {
               Label labelZero;
               Label labelActive;
               Point test;
               foreach (Control control in tableLayoutPanel1.Controls)
               {
                   Label labelFindZero = control as Label;

                   if (labelFindZero.Text == "")
                   {
                       labelZero = labelFindZero;
                       test = labelFindZero.Location;
                       break;
                   }
               }
               #region FindZeroLabel
               if (test.X == 5)
               {//X är vid första kolumn
                   if (test.Y == 2)
                       labelActive = label1;
                   else if (test.Y == 113)
                       labelActive = label5;
                   else if (test.Y == 224)
                       labelActive = label9;
                   else if (test.Y == 335)
                       labelActive = label16;
               }
               else if (test.X == 139)
               {//X är vid andra kolumn
                   if (test.Y == 2)
                       labelActive = label2;
                   else if (test.Y == 113)
                       labelActive = label6;
                   else if (test.Y == 224)
                       labelActive = label10;
                   else if (test.Y == 335)
                       labelActive = label13;
               }
               else if (test.X == 273)
               {//X är vid tredje kolumn
                   if (test.Y == 2)
                       labelActive = label3;
                   else if (test.Y == 113)
                       labelActive = label7;
                   else if (test.Y == 224)
                       labelActive = label11;
                   else if (test.Y == 335)
                       labelActive = label14;
               }
               else if (test.X == 402)
               {//X är vid fjärde kolumn
                   if (test.Y == 2)
                       labelActive = label4;
                   else if (test.Y == 113)
                       labelActive = label8;
                   else if (test.Y == 224)
                       labelActive = label12;
                   else if (test.Y == 335)
                       labelActive = label15;
               }
               #endregion
               if (e.KeyCode == Keys.A || e.KeyCode == Keys.Left)
               {
                
               }
           }
           */
        {
        }
    }
}
