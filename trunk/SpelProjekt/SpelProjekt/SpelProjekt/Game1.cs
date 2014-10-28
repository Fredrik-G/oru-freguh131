using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace SpelProjekt
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        #region variabeldeklarationer
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        Texture2D backgroundTexture;

        Texture2D playerTexture;
        Player player;

        Texture2D bulletTexture;
        List<Bullet> bulletList = new List<Bullet>();

        //Enemy
        List<Enemy> enemyList = new List<Enemy>();
        Texture2D enemyTextureBosse;
        Texture2D enemyTextureKalle;
        Texture2D enemyTextureNinjaBert;

        //Enum med alla olika motståndare.
        public enum EnemyName
        {
            kalle, //Standard
            bosse, //Snabb
            ninjaBert //Ninja!
        }

        //Variabel för att lägga in en fördröjning mellan varje tangenttryck.
        float buttonDelay = 0.0f;
        bool mouseClicked = false;
        bool keyClicked = false;
        //Variabel för att spara förfluten tid, används för att skapa motståndare i intervall.
        float timeSinceSpawn = 0.0f;

        //Keep track of the points for the player
        float points = 0;

        SpriteFont SegoeUIMono;
        // Location to draw the text
        Vector2 textLeft;
        Vector2 textMiddle;
        #endregion

        public Game1()
        {      
            graphics = new GraphicsDeviceManager(this);
            //this.graphics.IsFullScreen = true;
            //SetWindowSize(1280, 2014);
            //this.IsMouseVisible = true; 
            Content.RootDirectory = "Content";             
        }
        public void SetWindowSize(int x, int y)
        {
            graphics.PreferredBackBufferWidth = x;
            graphics.PreferredBackBufferHeight = y;
            graphics.ApplyChanges();
        }
        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            //Bakgrund
            backgroundTexture = Content.Load<Texture2D>("background");

            //Spelare
            playerTexture = Content.Load<Texture2D>("playerSprite");
            player = new Player(GraphicsDevice, new Vector2(100, 300), playerTexture);

            //Bullet 
            bulletTexture = Content.Load<Texture2D>("bulletSprite");

            //Enemy
            enemyTextureKalle = Content.Load<Texture2D>("kalle");
            enemyTextureBosse = Content.Load<Texture2D>("bosse");
            enemyTextureNinjaBert = Content.Load<Texture2D>("ninjaBert");

            //Text för att visa poäng och liv
            // Create the font
            SegoeUIMono = Content.Load<SpriteFont>("SpriteFont1");
            // Set text positions
            textMiddle = new Vector2(graphics.GraphicsDevice.Viewport.Width / 5f,
                graphics.GraphicsDevice.Viewport.Height / 30);
            textLeft = new Vector2(graphics.GraphicsDevice.Viewport.Width / 30,
                graphics.GraphicsDevice.Viewport.Height / 30);
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            player.Update(gameTime);
            UpdateInput();
            

            //Tar bort bullets som är utanför skärmen (och inte syns).
            for (int i = 0; i < bulletList.Count; i++)
            {
                bulletList[i].Update(gameTime);
                if (bulletList[i].Position.Y < -100.0f)
                    bulletList.RemoveAt(i);
            }
            //Minskar värdet på delayvariabeln.
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            buttonDelay -= elapsed;
            timeSinceSpawn += elapsed;

            CreateEnemyTime();

            /* Tar bort motståndare som försvunnit 
             * och kollar om ett skott har träffat en motståndare. */
            for (int i = 0; i < enemyList.Count; i++)
            {
                enemyList[i].Update(gameTime);
                if (enemyList[i].Position.Y > 900.0f)
                    enemyList.RemoveAt(i);

                //Kollar om en av spelarens skott träffade en motståndare.
                int collide = enemyList[i].CollisionBullet(bulletList);
                if (collide != -1)
                {
                    enemyList[i].Destroy();
                    enemyList.RemoveAt(i);
                    bulletList.RemoveAt(collide);

                    points += 200;
                }
                //Kollar om en motståndare har träffat spelaren och tar bort motståndaren i så fall.
                else if (player.CollisionTest(enemyList[i].Position, enemyList[i].Radius))
                    enemyList.RemoveAt(i);
                    
                //Tar bort motståndare som är långt borta och inte syns.
                else if (enemyList[i].Position.Y > 2000.0f)
                    enemyList.RemoveAt(i);
            }

            base.Update(gameTime);
        }

        private void UpdateInput()
        {     
            KeyboardState keyState = Keyboard.GetState();
            MouseState currentMouseState = Mouse.GetState();
            //Skjut ett skott
            if((keyState.IsKeyDown(Keys.Space) && keyClicked == false) ||
               (currentMouseState.LeftButton == ButtonState.Pressed && mouseClicked == false))
            {
                if (buttonDelay <= 0)
                {
                    Bullet shot = new Bullet(bulletTexture,
                     new Vector2(player.Position.X, player.Position.Y - 10.0f),
                     700.0f);

                    bulletList.Add(shot);
                    buttonDelay = 0.3f;
                    /* Visar att man har skjutit ett skott,
                     * detta gör att man inte kan hålla in skjutknappen hela tiden. */
                    mouseClicked = true;
                    keyClicked = true;
                }
             }
            //Nollställer när knappen släpps.
            if (currentMouseState.LeftButton == ButtonState.Released)
                mouseClicked = false;
            if (keyState.IsKeyUp(Keys.Space))
                keyClicked = false;

            //Styr player
            if (keyState.IsKeyDown(Keys.Up)    ||
                keyState.IsKeyDown(Keys.W))

                player.MoveUp();

            if (keyState.IsKeyDown(Keys.Down)  ||
                keyState.IsKeyDown(Keys.S))

                player.MoveDown();

            if (keyState.IsKeyDown(Keys.Left)  ||
                keyState.IsKeyDown(Keys.A))

                player.MoveLeft();

            if (keyState.IsKeyDown(Keys.Right) ||
                keyState.IsKeyDown(Keys.D))

                player.MoveRight();
            //Skapa motståndare
            if (keyState.IsKeyDown(Keys.E))
                if (buttonDelay <= 0.0f)
                {
                    CreateEnemy(EnemyName.kalle);
                    buttonDelay = 0.25f;
                }
            if (keyState.IsKeyDown(Keys.R))
                if (buttonDelay <= 0.0f)
                {
                    CreateEnemy(EnemyName.bosse);
                    buttonDelay = 0.25f;
                }
            if (keyState.IsKeyDown(Keys.T))
                if (buttonDelay <= 0.0f)
                {
                    CreateEnemy(EnemyName.ninjaBert);
                    buttonDelay = 0.25f;
                }
        }
        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            spriteBatch.Begin();
            spriteBatch.Draw(backgroundTexture, Vector2.Zero, Color.White);
            //Visa spelare
            player.Draw(spriteBatch);
            //Visa alla skott/bullets
            foreach (Bullet b in bulletList)
                b.Draw(spriteBatch);
            //Visa alla motståndare
            foreach (Enemy e in enemyList)
                e.Draw(spriteBatch);

            //Visa text
            DrawText(spriteBatch);

            spriteBatch.End();           
            base.Draw(gameTime);
        }
        //Skapar en ny random motståndare med 0.8 sekunders mellanrum.
        public void CreateEnemyTime()
        {
            if (timeSinceSpawn > 0.8f && timeSinceSpawn < 0.81f)
            {/* Den sista kollen görs så att det bara skapas en motståndare åt gången 
              * (det hade skapats flera hundra varje sekund annars) */
                
                Random r = new Random();
                int randomNumber = r.Next(3);

                if (randomNumber == 0)
                {
                    CreateEnemy(EnemyName.kalle);
                }
                else if (randomNumber == 1)
                {
                    CreateEnemy(EnemyName.bosse);
                }
                else if (randomNumber == 2)
                {
                    CreateEnemy(EnemyName.ninjaBert);
                }
            }
            if (timeSinceSpawn > 0.82f)
                timeSinceSpawn = 0;
        }
        public void CreateEnemy(EnemyName enemyName)
        {
            Random r = new Random();
            //Slumpar startposition
            int startY = r.Next(500);
            if (enemyName == EnemyName.ninjaBert)
            {
                Enemy enemy = new Enemy(enemyTextureNinjaBert,
                    new Vector2(900, startY), 200.0f);
                enemy.SetNinjaMoves((float)startY / 800.0f * 250.0f, 50.0f);
                enemyList.Add(enemy);
            }
            if (enemyName == EnemyName.bosse)
            {
                Enemy enemy = new Enemy(enemyTextureBosse,
                    new Vector2(900, startY), 330.0f);
                enemyList.Add(enemy);
            }
            if (enemyName == EnemyName.kalle)
            {
                Enemy enemy = new Enemy(enemyTextureKalle,
                    new Vector2(900, startY), 120.0f);
                enemyList.Add(enemy);
            }
        }
        public void DrawText(SpriteBatch TextBatch)
        {
            string output = "Lives: " + player.Lives.ToString();
            TextBatch.DrawString(SegoeUIMono, output, textLeft, Color.Tomato);
            string pointString = points.ToString();
            for (int i = pointString.Length; i < 8; i++)
                pointString = "0" + pointString;
            pointString = "Points: " + pointString;
            TextBatch.DrawString(SegoeUIMono, pointString, textMiddle, Color.Tomato);
        }
    }
}
