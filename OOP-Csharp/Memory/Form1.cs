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
    /// <summary>
    /// Programmet är uppbyggt av 16 labels (System.Windows.Forms.Label).
    /// Labels "får" en ikon m.h.a. en bokstav och en font/teckensnitt(Webdings) som är uppbyggd av ikoner istället för vanliga bokstäver.
    /// T.e.x 's' blir '?' med fonten.
    /// 
    /// Ikonerna visas/göms m.h.a att ändra färgen på label. 
    /// </summary>
    
    
    public partial class FormMemory : Form
    {
        private inputForm inputForm = new inputForm();
        private inputName inputName = new inputName();
        private Highscore highscore = new Highscore();
        Label första = null, andra = null;
        private int Elapsed_Time = 0;
        private int Moves = 0;
        private string CurrentPlayer;
        private void RitaIkoner()
        {//Funktion som ritar ut random ikon i rutorna.

            List<string> ikoner = new List<string>() 
            {//Lista med bokstäver som kommer representera ikoner i programmet.
                "!", "!", "N", "N", "H", "H", "j", "j",
                  "b", "b", "¨", "¨", "Y", "Y", "Ä", "Ä"
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

                    //Göm ikonen
                    ikonText.ForeColor = ikonText.BackColor;
                }
            }
        }

        public FormMemory()
        {
            InitializeComponent();
            RitaIkoner();

            this.inputName.ShowDialog(this);
            CurrentPlayer = inputName.NAME;
            string title = string.Format("Memory - {0}", CurrentPlayer);
            this.Text = title;
        }

        private void label_click(object sender, EventArgs e)
        {//Funktion som anropas när man trycker på en ruta.
            Label markerad = sender as Label;

            if (timer1.Enabled == true)
                //ignorera knapptryck när timern är aktiv
                return;
            if (markerad.ForeColor == Color.Blue)
                //Kolla så rutan inte redan är klickad
                return;

            if (första == null)
            {/*Om första är null så har man inte klickat än,
               dvs första gången man klickar.*/
                timerElapsed.Start();//Startar timer som visar förfluten tid.
                första = markerad;
                första.ForeColor = Color.Blue;
                return;
            }
            else
            {//annars är det andra gången man klickar
                andra = markerad;
                andra.ForeColor = Color.Blue;

                //Kollar om man har vunnit varje gång man har visat två ikoner. 
                CheckForWinner();
                
                //Ökar antal drag och visar antalet i en label.
                Moves++;
                labelMoves.Text = Convert.ToString(Moves);                               
            }

            if (första.Text == andra.Text)
            {/*om det är samma text så fortsätter dem visas
              * Nollställer första&andra så man kan börja om*/
                första = andra = null;
                return;
            }
            else
                /*annars så startas timern som väntar 0.8s
                 och döljer dem igen*/
                timer1.Start();
        }
        private void CheckForWinner()
        {/*Kontrollerar om  vinnare finns.
          * Returnerar true om vinnare finns, annars false */
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label ikonText = control as Label;

                if (ikonText != null)
                {
                    if (ikonText.ForeColor == ikonText.BackColor)
                        /*Vinnare finns om ingen rutas färg är samma som dess bakgrund.
                          dvs. om denna if aldrig blir sann */
                        return;
                }
            }
            //Om foreach-loopen går igenom allt och kommer hit så har en vinnare hittas
            string GameOver = string.Format("{0} vann på {1} sekunder med {2} drag. Bra jobbat!", CurrentPlayer, Elapsed_Time, Moves);
            MessageBox.Show(GameOver);
            
            return;
        }

        private void Delay_ToolStripMenuItem_Click(object sender, EventArgs e)
        {//Funktion för att låta användaren ändra hur länge omatchade ikoner ska visas.
            if (this.inputForm.ShowDialog(this) == DialogResult.OK)
            {//DELAY är en propery och används här för att läsa värdet användaren skrev in.
                timer1.Interval = inputForm.DELAY;
            }
        }

        private void börjaOmToolStripMenuItem_Click(object sender, EventArgs e)
        {//Börjar om
            if (MessageBox.Show("Är du säker på att du vill börja om?", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {    
                //Nollställer tid 
                Elapsed_Time = 0;
                labelTime.Text = "0";
                timerElapsed.Stop();

                //Nollställer antal drag
                Moves = 0;
                labelMoves.Text = "0";

                //Slumpar nya ikoner och ritar ut dem
                RitaIkoner();
            }
        }
        private void nySpelareToolStripMenuItem_Click(object sender, EventArgs e)
        {//Ny spelare.
            if (MessageBox.Show("Är du säker?", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                this.inputName.ShowDialog(this);
                CurrentPlayer = inputName.NAME;
                string title = string.Format("Memory - {0}", CurrentPlayer);
                this.Text = title;

                //Nollställer tid 
                Elapsed_Time = 0;
                labelTime.Text = "0";
                timerElapsed.Stop();

                //Nollställer antal drag
                Moves = 0;
                labelMoves.Text = "0";

                //Slumpar nya ikoner och ritar ut dem
                RitaIkoner();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {/*Timer som ger delay och döljer de senaste klickade rutorna
           Utan en timer så hade man inte hunnit se ikonen om de inte matchade.*/
            timer1.Stop();
            första.ForeColor = första.BackColor;
            andra.ForeColor = andra.BackColor;
            första = andra = null;
        }
        private void timer2_Tick(object sender, EventArgs e)
        {//Timer som används tillsammans med fusk.
            timer2.Stop();
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
        }
        private void timerElapsed_Tick(object sender, EventArgs e)
        {
            Elapsed_Time++;
            labelTime.Text = Convert.ToString(Elapsed_Time);
        }
        private void fuskaToolStripMenuItem_Click(object sender, EventArgs e)
        {//Funktion för att fuska, ändrar bakgrundsfärgen temporärt så man ser alla ikoner.
            timer2.Start();
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
        }
        private void aktiveraFuskToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (!fuskaToolStripMenuItem.Visible)
            {//Sätter på fusk
                fuskaToolStripMenuItem.Visible = true;
                this.fuskaToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Space)));
            }
            else
            {//Stänger av fusk
                fuskaToolStripMenuItem.Visible = false;
                this.fuskaToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)(System.Windows.Forms.Keys.F20));
                //Visste inte hur man "bindar bort" och går inte att tilldela null, så jag binda den till random knapp.
            }
            
        }
    }
}
