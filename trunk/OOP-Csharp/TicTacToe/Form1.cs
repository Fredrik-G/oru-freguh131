using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace TicTacToe
{
    public partial class TicTacToe : Form
    {
        private int x = 1;
        private int y = 1;
        private int moves = 0;
        private bool spelare = true;
        private int spelareX = 0, spelareY = 0;
        public TicTacToe()
        {
            InitializeComponent();
        }

        private void TicTacToe_Load(object sender, EventArgs e)
        {
        }
        private void DisableAll()
        {
            richTextBox1.Enabled = false;
            richTextBox2.Enabled = false;
            richTextBox3.Enabled = false;
            richTextBox4.Enabled = false;
            richTextBox5.Enabled = false;
            richTextBox6.Enabled = false;
            richTextBox7.Enabled = false;
            richTextBox8.Enabled = false;
            richTextBox9.Enabled = false;
        }
        private bool Key(KeyEventArgs e, RichTextBox RTB)
        {
            if (e.KeyCode == Keys.Enter && RTB.Text == "")
            {
                if (spelare)
                {
                    RTB.Text = "X";
                    spelare = !spelare;
                    moves++;
                }
                else if (!spelare)
                {
                    RTB.Text = "O";
                    spelare = !spelare;
                    moves++;
                }
                label1.Visible = false;
                checkBoxO.Visible = false;
                checkBoxX.Visible = false;
                return true;
            }
            else return false;
        }
        private void KeyPress(KeyEventArgs e)
        {
            if ( (e.KeyCode == Keys.Left || e.KeyCode == Keys.A) && x>0)
                this.x -= 1;
            else if ( (e.KeyCode == Keys.Right || e.KeyCode == Keys.D) && x<2)
                this.x += 1;
            else if ( (e.KeyCode == Keys.Up || e.KeyCode == Keys.W) && y<2)
                this.y += 1;
            else if ( (e.KeyCode == Keys.Down || e.KeyCode == Keys.S) && y>0)
                this.y -= 1;

            #region GoToBox
            if (x == 0 && y == 2)
            {
                DisableAll();
                richTextBox1.Enabled = true;
                richTextBox1.Focus();
            }
            else if (x == 1 && y == 2)
            {
                DisableAll();
                richTextBox2.Enabled = true;
                richTextBox2.Focus();
            }
            else if (x == 2 && y == 2)
            {
                DisableAll();
                richTextBox3.Enabled = true;
                richTextBox3.Focus();
            }
            else if (x == 0 && y == 1)
            {
                DisableAll();
                richTextBox4.Enabled = true;
                richTextBox4.Focus();
            }
            else if (x == 1 && y == 1)
            {
                DisableAll();
                richTextBox5.Enabled = true;
                richTextBox5.Focus();
            }
            else if (x == 2 && y == 1)
            {
                DisableAll();
                richTextBox6.Enabled = true;
                richTextBox6.Focus();
            }
            else if (x == 0 && y == 0)
            {
                DisableAll();
                richTextBox7.Enabled = true;
                richTextBox7.Focus();
            }
            else if (x == 1 && y == 0)
            {
                DisableAll();
                richTextBox8.Enabled = true;
                richTextBox8.Focus();
            }
            else if (x == 2 && y == 0)
            {
                DisableAll();
                richTextBox9.Enabled = true;
                richTextBox9.Focus();
            }
            #endregion
            
        }

        private void CheckWinner()
        {
            if (moves >= 5)
            {
                if (((richTextBox1.Text == "X" && richTextBox2.Text == "X" && richTextBox3.Text == "X") ||
                     (richTextBox4.Text == "X" && richTextBox5.Text == "X" && richTextBox6.Text == "X") ||
                     (richTextBox7.Text == "X" && richTextBox8.Text == "X" && richTextBox9.Text == "X"))
                    //^vågrätt
                                                     ||
                 ((richTextBox1.Text == "X" && richTextBox4.Text == "X" && richTextBox7.Text == "X") ||
                  (richTextBox2.Text == "X" && richTextBox5.Text == "X" && richTextBox8.Text == "X") ||
                  (richTextBox3.Text == "X" && richTextBox6.Text == "X" && richTextBox9.Text == "X"))
                    //^lodrätt
                                                     ||
                 ((richTextBox1.Text == "X" && richTextBox5.Text == "X" && richTextBox9.Text == "X") ||
                  (richTextBox3.Text == "X" && richTextBox5.Text == "X" && richTextBox7.Text == "X")))
                    //^diagonalt

                    Winner(spelareX);
                    //X vann

                else if (((richTextBox1.Text == "O" && richTextBox2.Text == "O" && richTextBox3.Text == "O") ||
                     (richTextBox4.Text == "O" && richTextBox5.Text == "O" && richTextBox6.Text == "O") ||
                     (richTextBox7.Text == "O" && richTextBox8.Text == "O" && richTextBox9.Text == "O"))
                    //^vågrätt
                                                     ||
                 ((richTextBox1.Text == "O" && richTextBox4.Text == "O" && richTextBox7.Text == "O") ||
                  (richTextBox2.Text == "O" && richTextBox5.Text == "O" && richTextBox8.Text == "O") ||
                  (richTextBox3.Text == "O" && richTextBox6.Text == "O" && richTextBox9.Text == "O"))
                    //^lodrätt
                                                     ||
                 ((richTextBox1.Text == "O" && richTextBox5.Text == "O" && richTextBox9.Text == "O") ||
                  (richTextBox3.Text == "O" && richTextBox5.Text == "O" && richTextBox7.Text == "O")))
                    //^diagonalt  
           
                    Winner(spelareY);

                else if (moves > 8)
                {
                  DisableAll();
                  richTextBoxWinner.Visible = true;
                  richTextBoxWinner.Text = "Oavgjort...";
                  buttonRestart.Visible = true;
                }
            }
             
        }
    
        #region KeyDown
        private void richTextBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if ( !Key(e, richTextBox1) )
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox2_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox2))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox3_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox3))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox4_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox4))
                KeyPress(e);
        }
        private void richTextBox5_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox5))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox6_KeyDown(object sender, KeyEventArgs e)
        {
            if ( ! Key(e, richTextBox6))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox7_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox7))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox8_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox8))
                KeyPress(e);
            CheckWinner();
        }
        private void richTextBox9_KeyDown(object sender, KeyEventArgs e)
        {
            if (!Key(e, richTextBox9))
                KeyPress(e);
            CheckWinner();
        }
        #endregion
        private void Winner(int player)
        {
            if (!spelare)
            {
                spelareX++;
                DisableAll();
                richTextBoxWinner.Visible = true;
                richTextBoxWinner.Text = "X vann!";
                buttonRestart.Visible = true;

                labelScoreX.Text = Convert.ToString(spelareX);
                labelScoreO.Text = Convert.ToString(spelareY);
            }
            else if (spelare)
            {
                spelareY++;
                DisableAll();
                richTextBoxWinner.Visible = true;
                richTextBoxWinner.Text = "O vann!";
                buttonRestart.Visible = true;

                labelScoreO.Text = Convert.ToString(spelareX);
                labelScoreO.Text = Convert.ToString(spelareY);

            }
        }
        private void Clear()
        {
            buttonRestart.Visible = false;
            richTextBoxWinner.Visible = false;
            richTextBox1.Clear();
            richTextBox2.Clear();
            richTextBox3.Clear();
            richTextBox4.Clear();
            richTextBox5.Clear();
            richTextBox6.Clear();
            richTextBox7.Clear();
            richTextBox8.Clear();
            richTextBox9.Clear();
           
        }
        private void buttonRestart_Click(object sender, EventArgs e)
        {
            Clear();
            spelare = true;
            moves = 0; 
            richTextBox5.Enabled = true;
            richTextBox5.Focus();
            label1.Visible = true;
            checkBoxO.Visible = true;
            checkBoxX.Visible = true;
        }

        private void checkBoxX_Click(object sender, EventArgs e)
        {    
            checkBoxO.Checked = false;
            spelare = true;
            richTextBox5.Focus();
        }

        private void checkBoxO_Click(object sender, EventArgs e)
        {
            checkBoxX.Checked = false;
            spelare = false;
            richTextBox5.Focus();
        }


    }
}
