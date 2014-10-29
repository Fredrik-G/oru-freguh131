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

        /* Spelet har tre olika lägen, en som agerar som startskärm,
         * en som är själv spelet,
         * och en som visas på slutet om man tex får slut på liv.
         * TODO: lägg in hjälpmeny. */
        public enum GameState
        {
            StartScreen,
            Running,
            EndScreen
        }
        //Spelet börjar med startscreen.
        GameState gameState = GameState.StartScreen;
        //Start/slut-meny
        Texture2D startScreen;
        Texture2D endScreen;
        //Bakgrundsbild
        Texture2D backgroundTexture;
        //Player
        Texture2D playerTexture;
        Player player;

        //Bullet
        Texture2D bulletTexture;
        List<Bullet> bulletList = new List<Bullet>();

        //Enemy
        List<Enemy> enemyList = new List<Enemy>();
        Texture2D enemyTextureBosse;
        Texture2D enemyTextureKalle;
        Texture2D enemyTextureNinjaBert;
        Texture2D enemyTextureDöskalle;
        float bosseSpeed = 0.0f,
              kalleSpeed = 0.0f,
              ninjaBertSpeed = 0.0f,
              döskalleSpeed = 0.0f;
        int bosseCount = 0;
        //Enum med alla olika motståndare.
        public enum EnemyName
        {
            kalle, //Standard
            bosse, //Snabb
            ninjaBert, //Ninja!
            döskalle //Instant kill
        }

        //Friendly
        List<Friendly> friendlyList = new List<Friendly>();
        Texture2D friendlyTextureFågelnRoger;
        Texture2D friendlyTextureFågelnRogerMad;
        Texture2D friendlyTextureJolt;
        float fågelnRogerSpeed = 0.0f,
              joltSpeed = 0.0f;
        int fågelHits = 0;

        public enum FriendlyName
        {
            fågelnRoger, //Ger extrapoäng
            jolt //Ger extraliv
        }

        //Variabel för att lägga in en fördröjning mellan varje tangenttryck.
        float buttonDelay = 0.0f;
        bool mouseClicked = false;
        bool keyClicked = false;
        //Variabel för att spara förfluten tid, används för att skapa motståndare i intervall.
        float timeSinceEnemySpawn = 0.0f;
        float timeSinceFriendlySpawn = 0.0f;
        //Keep track of the points for the player
        float points = 0;
        //Random
        static private Random random = new Random();
        
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
            bosseSpeed = 330.0f;
            kalleSpeed = 110.0f;
            ninjaBertSpeed = 220.0f;
            döskalleSpeed = 500.0f;

            fågelnRogerSpeed = 200.0f;
            joltSpeed = 150.0f;
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

            //Start/slut-meny
            startScreen = Content.Load<Texture2D>("startGame");
            endScreen = Content.Load<Texture2D>("endGame");

            //Spelare
            playerTexture = Content.Load<Texture2D>("playerSprite");
            player = new Player(GraphicsDevice, new Vector2(100, 300), playerTexture);

            //Bullet 
            bulletTexture = Content.Load<Texture2D>("bulletSprite");

            //Enemy
            enemyTextureKalle = Content.Load<Texture2D>("kalle");
            enemyTextureBosse = Content.Load<Texture2D>("bosse");
            enemyTextureNinjaBert = Content.Load<Texture2D>("ninjaBert");
            enemyTextureDöskalle = Content.Load<Texture2D>("döskalle");
          
            //Friendly
            friendlyTextureFågelnRoger = Content.Load<Texture2D>("fågelnRoger");
            friendlyTextureFågelnRogerMad = Content.Load<Texture2D>("fågelnRogerMad");
            friendlyTextureJolt = Content.Load<Texture2D>("jolt");

            //Text för att visa poäng och liv
            SegoeUIMono = Content.Load<SpriteFont>("SpriteFont1");
            //Positionsvektor där texten ska visas
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

            //Minskar värdet på delayvariabeln.
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            buttonDelay -= elapsed;
            timeSinceEnemySpawn += elapsed;
            timeSinceFriendlySpawn += elapsed;

            //Om start/slut-meny visas
            if (gameState == GameState.StartScreen || gameState == GameState.EndScreen)
                UpdateSplashScreen();
            else //Spelet körs
            {
                //Kollar om spelet är slut
                if (player.Lives < 0)
                {
                    gameState = GameState.EndScreen;             
                    enemyList.Clear();
                    friendlyList.Clear();
                    bulletList.Clear();
                }

                player.Update(gameTime);
                UpdateInput();
                CreateEnemyTime();
                CreateFriendlyTime();

                /* Tar bort motståndare som försvunnit 
                 * och kollar om ett skott har träffat någon. */
                for (int i = 0; i < enemyList.Count; i++)
                {
                    enemyList[i].Update(gameTime);
                    if (enemyList[i].Position.Y > 900.0f)
                        enemyList.RemoveAt(i);

                    //Kollar om en av spelarens skott träffade en motståndare.
                    int collide = enemyList[i].CollisionBullet(bulletList);
                    if (collide != -1)
                    {
                        if (enemyList[i].Speed == ninjaBertSpeed)
                            points += 500;
                        else if (enemyList[i].Speed == kalleSpeed)
                            points += 100;
                        else if (enemyList[i].Speed == bosseSpeed)
                            points += 300;

                        enemyList[i].Destroy();
                        enemyList.RemoveAt(i);
                        bulletList.RemoveAt(collide);

                    }
                    //Kollar om en motståndare har träffat spelaren och tar bort motståndaren i så fall.
                    else if (player.CollisionTest(enemyList[i].Position, enemyList[i].Radius))
                    {
                        if (enemyList[i].Speed == döskalleSpeed)
                            player.Lives = 0;
                        enemyList.RemoveAt(i);
                        player.Lives--;
                    }
                    //Tar bort motståndare som är långt borta och inte syns.
                    else if (enemyList[i].Position.Y > 2000.0f)
                        enemyList.RemoveAt(i);
                }
                //Gör samma sak för friendly
                for (int i = 0; i < friendlyList.Count; i++)
                {
                    friendlyList[i].Update(gameTime);
                    //    if (friendlyList[i].Position.Y > 900.0f)
                    //     friendlyList.RemoveAt(i);

                    //Kollar om en av spelarens skott träffade en motståndare.
                    int collide = friendlyList[i].CollisionBullet(bulletList);
                    if (collide != -1)
                    {
                        if (friendlyList[i].Speed == fågelnRogerSpeed)
                            points -= 1000.0f;

                        friendlyList[i].Mad = 1;
                        friendlyList[i].Destroy();
                //        friendlyList.RemoveAt(i);
                        bulletList.RemoveAt(collide);
                        if (fågelHits == 0) fågelHits = 1;
                        else if (fågelHits == 1) fågelHits = 2;
                        else if (fågelHits == 2) fågelHits = 3;
                    }
                    /*Kollar om en friendly har träffat spelaren och tar bort den i så fall.
                     * Ger även extrapoäng.*/
                    else if (player.CollisionTest(friendlyList[i].Position, friendlyList[i].Radius))
                    {
                        if (friendlyList[i].Speed == fågelnRogerSpeed)
                        {
                            points += 200;      
                     
                        }
                        else if (friendlyList[i].Speed == joltSpeed)
                            player.Lives += 2;

                        friendlyList.RemoveAt(i);
                    }
                    //Tar bort friendly som är långt borta och inte syns.
                    else if (friendlyList[i].Position.Y > 2000.0f)
                        friendlyList.RemoveAt(i);
                }

                //Tar bort bullets som är utanför skärmen (och inte syns).
                for (int i = 0; i < bulletList.Count; i++)
                {
                    bulletList[i].Update(gameTime);
                    if (bulletList[i].Position.Y < -100.0f)
                        bulletList.RemoveAt(i);
                }
            }
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
                    //Minus fem poäng för varje skott.
                    points -= 5;
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
            if (keyState.IsKeyDown(Keys.F))
                if (buttonDelay <= 0.0f)
                {
                    CreateFriendly(FriendlyName.fågelnRoger);
                    buttonDelay = 0.25f;
                }
            if (keyState.IsKeyDown(Keys.G))
                if (buttonDelay <= 0.0f)
                {
                    CreateFriendly(FriendlyName.jolt);
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

            if (gameState == GameState.StartScreen)
                DrawStartScreen();
            else if (gameState == GameState.Running)
            {

                spriteBatch.Begin();
                spriteBatch.Draw(backgroundTexture, new Rectangle(0, 0,
                    graphics.PreferredBackBufferWidth,
                    graphics.PreferredBackBufferHeight), Color.White);
                //Visa spelare
                player.Draw(spriteBatch);
                //Visa alla skott/bullets
                foreach (Bullet b in bulletList)
                    b.Draw(spriteBatch);
                //Visa alla motståndare
                foreach (Enemy e in enemyList)
                    e.Draw(spriteBatch);
                //Visa friendly
                foreach (Friendly f in friendlyList)
                    f.Draw(spriteBatch);
                //Visa text
                DrawText(spriteBatch);

                spriteBatch.End();
            }
            else if (gameState == GameState.EndScreen)
                DrawEndScreen();

            base.Draw(gameTime);
        }
        //Visa startmenyn
        private void DrawStartScreen()
        {
            spriteBatch.Begin();
            spriteBatch.Draw(startScreen, new Rectangle(0, 0,
                    graphics.PreferredBackBufferWidth,
                    graphics.PreferredBackBufferHeight), Color.White);
            spriteBatch.End();
        }
        //Visa slutmenyn
        private void DrawEndScreen()
        {
            spriteBatch.Begin();
            spriteBatch.Draw(endScreen, new Rectangle(0, 0,
                    graphics.PreferredBackBufferWidth,
                    graphics.PreferredBackBufferHeight), Color.White);
            spriteBatch.End();
        }
        private void UpdateSplashScreen()
        {
            KeyboardState keyState = Keyboard.GetState();
            if (keyState.IsKeyDown(Keys.Enter))
                gameState = GameState.Running;               
        }

        //Skapar en ny random motståndare med x sekunders mellanrum.
        public void CreateEnemyTime()
        {          
            if (timeSinceEnemySpawn > 0.8f && timeSinceEnemySpawn < 0.81f)
            {/* Den sista kollen görs så att det bara skapas en motståndare åt gången 
              * (det hade skapats flera hundra varje sekund annars) */              
                int randomNumber = random.Next(3);

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
            if (timeSinceEnemySpawn > 0.82f)
                timeSinceEnemySpawn = 0;
        }
        public void CreateFriendlyTime()
        {
            if (timeSinceFriendlySpawn > 2.2f && timeSinceFriendlySpawn < 2.21f)
            {
                int randomNumber = random.Next(2);
                if (randomNumber == 0)
                {
                    CreateFriendly(FriendlyName.fågelnRoger);
                }
                else if (randomNumber == 1)
                {
                    CreateFriendly(FriendlyName.jolt);
                }
            }
            if (timeSinceFriendlySpawn > 2.22f)
                timeSinceFriendlySpawn = 0;
        }
        public void CreateEnemy(EnemyName enemyName)
        {
            MouseState mousePos = Mouse.GetState();
            //Slumpar startposition
            int startY = random.Next(480);

            if (fågelHits == 3)
            {
                Enemy enemy = new Enemy(enemyTextureDöskalle,
                    new Vector2(900, mousePos.Y), döskalleSpeed);
                enemyList.Add(enemy);
                fågelHits = 0;
            }
            else
            {
                if (enemyName == EnemyName.ninjaBert)
                {
                    Enemy enemy = new Enemy(enemyTextureNinjaBert,
                        new Vector2(900, mousePos.Y), ninjaBertSpeed);
                    enemy.SetNinjaMoves((float)startY / 800.0f * 250.0f, 50.0f);
                    enemyList.Add(enemy);
                }
                if (enemyName == EnemyName.bosse && bosseCount <= 4)
                {
                    Enemy enemy = new Enemy(enemyTextureBosse,
                        new Vector2(900, mousePos.Y), bosseSpeed);
                    enemyList.Add(enemy);
                    bosseCount++;
                }
                if (enemyName == EnemyName.bosse && bosseCount >= 5)
                {//Var femte bosse är en MEGAbosse och är mycket snabbare
                    Enemy enemy = new Enemy(enemyTextureBosse,
                        new Vector2(900, mousePos.Y), bosseSpeed + 300);
                    enemyList.Add(enemy);
                    bosseCount = 0;
                }
                if (enemyName == EnemyName.kalle)
                {
                    Enemy enemy = new Enemy(enemyTextureKalle,
                        new Vector2(900, mousePos.Y), kalleSpeed);
                    enemyList.Add(enemy);
                }
            }
        }
        public void CreateFriendly(FriendlyName friendlyName)
        {
            //Slumpar startposition
            int startY = random.Next(500);
            if (friendlyName == FriendlyName.fågelnRoger)
            {
                Friendly enemy = new Friendly(friendlyTextureFågelnRoger,
                    new Vector2(900, startY), fågelnRogerSpeed, 20.0f, friendlyTextureFågelnRogerMad);
                friendlyList.Add(enemy);
            }
            if (friendlyName == FriendlyName.jolt)
            {
                Friendly enemy = new Friendly(friendlyTextureJolt,
                    new Vector2(900, startY), joltSpeed, -20.0f);
                friendlyList.Add(enemy);
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
