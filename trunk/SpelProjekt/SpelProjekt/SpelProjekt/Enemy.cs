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
    class Enemy
    {
        Vector2 position;
        Texture2D picture;
        float speed = 150.0f;
        float deltaX = 0.0f;
        float yLength = 0.0f;
        float yStart = 0.0f;

        float radius = 40.0f;
        public float Radius{ get { return radius; } }

        public Enemy(Texture2D picture, Vector2 startPosition, float speed)
        {
            this.picture = picture;
            position = startPosition;
            this.speed = speed;
        }
        public void SetNinjaMoves(float deltaX, float yLength)
        {
            this.deltaX = deltaX;
            this.yLength = yLength;
            yStart = position.Y;
        }
        public Vector2 Position
        {
            get { return position; }
        }
        public void Draw(SpriteBatch batch)
        {
            batch.Draw(picture, position, null, Color.White, 0.0f, new Vector2(
            40.0f, 20.0f), 1.0f, SpriteEffects.None, 0.0f);
        }
        public void Update(GameTime gameTime)
        {
            //Ninja moves
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            position.Y += deltaX * elapsed;
            if (Position.Y < yStart - yLength || Position.Y > yStart + yLength)
                deltaX *= -1.0f;
            //Flyttar motståndaren åt vänster
            position.X -= speed * elapsed;         
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
        public void Destroy()
        {
             
        }
    }
}
