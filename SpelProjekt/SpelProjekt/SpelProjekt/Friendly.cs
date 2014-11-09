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
        public Vector2 Position { get { return position; } }  
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
        /// <summary>
        /// Konstruktor för friendly.
        /// </summary>
        /// <param name="picture">Textur som ska visas för friendly</param>
        /// <param name="startPosition">Startposition</param>
        /// <param name="speed">Hastighet</param>
        /// <param name="deltaX"> </param>
        /// <param name="madPicture">Default parameter som används med fågeln Roger för att gå åt andra hållet.</param>
        public Friendly(Texture2D picture, Vector2 startPosition, float speed, float deltaX, Texture2D madPicture = null)
        {
            this.picture = picture;
            position = startPosition;
            this.speed = speed;
            this.deltaX = deltaX;
            this.madPicture = madPicture;
        }     
        /// <summary>
        /// Visa friendly.
        /// </summary>
        /// <param name="batch"></param>
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
        /// <summary>
        /// Uppdaterar friendlyns position.
        /// </summary>
        /// <param name="gameTime"></param>
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
        /// <summary>
        /// Kollar om en av spelarens skott träffade en motståndare.
        /// </summary>
        /// <param name="bulletList">Tar emot en lista innehållande alla skott.</param>
        /// <returns>Returnerar skottets position i listan om ett skott träffade en friendly.
        /// Om inget skott träffade så returneras -1.</returns>
        public int CollisionBullet(List<Bullet> bulletList)
        {
            for (int i = 0; i < bulletList.Count; i++)
            {
                if ((bulletList[i].Position - position).Length() < radius)
                    return i;
            }
            return -1;
        }
        /// <summary>
        /// Används för att flytta fågeln Roger åt höger istället för vänster.
        /// </summary>
        /// <param name="gameTime"></param>
        public void MoveBack(GameTime gameTime)
        {
            float elapsed = (float)gameTime.ElapsedGameTime.TotalSeconds;
            //Flyttar åt höger
            position.X += speed * elapsed;
        }
    }
}
