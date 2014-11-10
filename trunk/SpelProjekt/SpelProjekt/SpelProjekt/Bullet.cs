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
    class Bullet
    {
        Vector2 position;
        public Vector2 Position { get { return position; } }
        Texture2D picture;
        float speed;
        /// <summary>
        /// Konstruktor för bullet
        /// </summary>
        /// <param name="picture">Textur som ska visas för bullet.</param>
        /// <param name="startPos">Startposition</param>
        /// <param name="updateSpeed">Kulans hastighet.</param>
        public Bullet(Texture2D picture, Vector2 startPos, float updateSpeed)
        {
            this.picture = picture;
            position = startPos;
            speed = updateSpeed;
        }
        /// <summary>
        /// Visar kulan.
        /// </summary>
        /// <param name="batch"></param>
        public void Draw(SpriteBatch batch)
        {
            batch.Draw(picture, position, null, Color.White, 0.0f, new Vector2(10.0f, 10.0f),
                       0.1f, SpriteEffects.None, 1.0f);
        }
        /// <summary>
        /// Uppdaterar kulans position.
        /// </summary>
        /// <param name="gameTime"></param>
        public void Update(GameTime gameTime)
        {
            position.X += speed * (float)gameTime.ElapsedGameTime.TotalSeconds;
        }
    }
}
