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
    class Friendly
    {
        Vector2 position;
        Texture2D picture;
        Texture2D madPicture;
        float speed;
        public float Speed { get { return speed; } }
        float deltaX = 0.0f;
        float radius = 40.0f;
        public float Radius { get { return radius; } }

        /* Variabel som används för att visa att friendly blev arg
         * och att den går tillbaka. */
        int mad = 0;
        public int Mad
        {
            set { mad = value; }
            get { return mad; }
        }

        public Friendly(Texture2D picture, Vector2 startPosition, float speed, float deltaX, Texture2D madPicture = null)
        {
            this.picture = picture;
            position = startPosition;
            this.speed = speed;
            this.deltaX = deltaX;
            this.madPicture = madPicture;
        }
        public Vector2 Position { get { return position; }
        }
        public void Draw(SpriteBatch batch)
        {
            if (mad == 0)
                batch.Draw(picture, position, null, Color.White, 0.0f, new Vector2(
                    40.0f, 20.0f), 1.0f, SpriteEffects.None, 0.0f);
            else if (mad == 1 && madPicture != null)
            {          
                batch.Draw(madPicture, position, null, Color.White, 0.0f, new Vector2(
                    40.0f, 20.0f), 1.0f, SpriteEffects.None, 0.0f);
            }
        }
        public void Update(GameTime gameTime)
        {
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            //Flyttar den åt vänster
            if (mad == 0)
                position.X -= speed * elapsed;
            else if (mad == 1)
                position.X += speed * elapsed;
            position.Y += deltaX * elapsed;
        }
        public int CollisionBullet(List<Bullet> bulletList)
        {//Kollar om en av spelarens skott träffade en motståndare.
            for (int i = 0; i < bulletList.Count; i++)
            {
                if ((bulletList[i].Position - position).Length() < radius)
                    return i;
            }
            return -1;
        }
        public void MoveBack(GameTime gameTime)
        {
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            //Flyttar åt höger
            position.X += speed * elapsed;
        }
        public void Destroy()
        {

        }
    }
}
