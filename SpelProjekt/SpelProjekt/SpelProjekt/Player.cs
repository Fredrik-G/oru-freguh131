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

        float blinkTime = 0.0f;
        float blinkTimeTotal = 0.0f;
        bool blinkOn = false;
        bool recoveringActive = false;
        const float recoverLength = 3.0f;

        //Total number of lives
        int lives = 5;
        public int Lives
        {
            set { lives = value; }
            get { return lives; }
        }

        // This method is called when the Player is created
        public Player(GraphicsDevice device, Vector2 position, Texture2D sprite)
        {
            // The position that is passed in is now set to the position above
            this.position = position;

            // Set the Texture2D
            playerSprite = sprite;
            
            // Setup origin
            spriteOrigin.X = (float)playerSprite.Width / 2.0f;
            spriteOrigin.Y = (float)playerSprite.Height / 2.0f;

            // Set window dimensions
            windowHeight = device.Viewport.Height;
            windowWidth = device.Viewport.Width;
        }
        // Draw the player
        public void Draw(SpriteBatch batch)
        {
            batch.Draw(playerSprite, position, null, Color.White,
                       0.0f, spriteOrigin, 1.0f, SpriteEffects.None, 0.0f);
            //         ^rotation           ^scale
        }
        // Update - for animation
        public void Update(GameTime gameTime)
        {
            if (position.Y < 0) 
                position.Y = 0.0f;
            else if (position.Y > windowHeight)
                position.Y = windowHeight;
            else if (position.X < 0)
                position.X = 0.0f;
            else if (position.X > windowWidth)
                position.X = windowWidth;

            position.X = Mouse.GetState().X;
            position.Y = Mouse.GetState().Y;

            if (recoveringActive)
            {
                const float blinkTimeSlice = 1.0f / 15.0f;
                float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
                blinkTime += elapsed;
                blinkTimeTotal += elapsed;
                if (blinkTimeTotal > recoverLength)
                    recoveringActive = false;
                else
                {
                    if (blinkTime > blinkTimeSlice)
                    {
                        blinkOn = !blinkOn;
                        blinkTime = 0.0f;
                    }
                }
            }
        }
        public bool CollisionTest(Vector2 point, float radius)
        {
            if ((point - position).Length() < this.radius + radius)
            {
                if (!recoveringActive)
                {
                    lives--;
                    recoveringActive = true;
                    blinkTimeTotal = 0.0f;
                }
                
                return true;
            }
            return false;
        }

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
