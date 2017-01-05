#ifndef _SHIPS_HPP_
#define _SHIPS_HPP_

#include "SFML/Graphics.hpp"
#include "FDX_Geo/FDX_Geo.hpp"

#include "IController.hpp"
#include "World.hpp"

using namespace fdx;

namespace DSI
{

    //Ship, player or enemy
    class Ship : public sf::Drawable
    {
        /*  Members */

        /*Phyisics*/
        private:

            //Position and size
            arrow::Rct r;

        /*Looks*/
        private:

            //Sprite
            sf::Sprite sp;

        /*Enviroment*/
        private:

            World &world;//World to interact with

        /*Controls*/
        private:

            //Pointer to the controller of this ship, owned by this (free at end)
            IController *ptr_controller;

        /* Constructors, copy control */

        /*Constructors*/
        public:

            //Complete constructor
            Ship(const arrow::Vct &icenter, sf::Texture &itexture, World &iworld, IController *iptr_controller=nullptr);

            //Destructor
            ~Ship();

        /* Methods */

        /*Drawing*/
        public:

            //Draw the ship
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        private:

            //Create the sprite
            void create_sprite(const sf::Texture &texture);

        /*Update*/
        public:

            //Update the ship's status (process info from controller)
            void update();
    };
}

#endif // _SHIPS_HPP_
