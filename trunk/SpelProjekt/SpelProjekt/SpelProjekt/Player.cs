using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace SpelProjekt
{
    class Player
    {
        Vector2 position;
        public Vector2 Position { get { return position; } }
        Texture2D playerSprite;
        Vector2 spriteOrigin;
        int windowWidth, windowHeight;

        float radius = 50.0f;

        //Antal liv
        int lives = 5;
        public int Lives
        {
            set { lives = value; }
            get { return lives; }
        }

        /// <summary>
        /// Konstruktor för player.
        /// </summary>
        public Player(GraphicsDevice device, Vector2 position, Texture2D sprite)
        {
            this.position = position;
            playerSprite = sprite;
            
            //Ange startposition.
            spriteOrigin.X = (float)playerSprite.Width / 2.0f;
            spriteOrigin.Y = (float)playerSprite.Height / 2.0f;

            windowHeight = device.Viewport.Height;
            windowWidth = device.Viewport.Width;
        }
        /// <summary>
        /// Visa spelaren.
        /// </summary>
        /// <param name="batch"></param>
        public void Draw(SpriteBatch batch)
        {
            batch.Draw(playerSprite, position, null, Color.White,
                       0.0f, spriteOrigin, 1.0f, SpriteEffects.None, 0.0f);
            //         ^rotation           ^scale
        }
        /// <summary>
        /// Uppdaterar spelarens positon.
        /// </summary>
        /// <param name="gameTime"></param>
        /// <param name="usingMouse">Skickar med om man styr spelaren med musen eller inte.</param>
        public void Update(GameTime gameTime, bool usingMouse)
        {
            if (position.Y < 0) 
                position.Y = 0.0f;
            else if (position.Y > windowHeight)
                position.Y = windowHeight;
            else if (position.X < 0)
                position.X = 0.0f;
            else if (position.X > windowWidth)
                position.X = windowWidth;

            if (usingMouse)
            {
                position.X = Mouse.GetState().X;
                position.Y = Mouse.GetState().Y;
            }
        }
        /// <summary>
        /// Kollar om spelaren har krockat med någon/något.
        /// </summary>
        /// <param name="point">Positionen på det objekt man kontrollerar kollision med.</param>
        /// <param name="radius">Objektets radius (storlek).</param>
        /// <returns>Returnerar sant om spelaren har krockat med ett objekt.
        /// Annars returneras false.</returns>
        public bool CollisionTest(Vector2 point, float radius)
        {
            if ((point - position).Length() < this.radius + radius)            
                return true;
            return false;
        }
        /// <summary>
        /// Används tillsammans med tangentbordet för att
        /// flytta spelaren i olika riktningar.
        /// </summary>
        public void MoveUp()
        {//Flyttas 4 pixlar åt gången.
            position.Y -= 4.0f;
        }
        public void MoveDown()
        {
            position.Y += 4.0f;
        }
        public void MoveRight()
        {
            position.X += 4.0f;
        }
        public void MoveLeft()
        {
            position.X -= 4.0f;
        }
    }
}
