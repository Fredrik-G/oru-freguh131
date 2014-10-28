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
        Texture2D picture;
        float speed;

        public Bullet(Texture2D picture, Vector2 startPos, float updateSpeed)
        {
            this.picture = picture;
            position = startPos;
            speed = updateSpeed;
        }
        public Vector2 Position { get { return position; } }

        public void Draw(SpriteBatch batch)
        {
            batch.Draw(picture, position, null, Color.White, 0.0f, new Vector2(10.0f, 10.0f),
                       0.1f, SpriteEffects.None, 1.0f);
        }
        public void Update(GameTime gameTime)
        {
            position.X += speed * (float)gameTime.ElapsedGameTime.TotalSeconds;
        }
    }
}
