#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
class Ball{
	private:
	sf::CircleShape ball;
	sf::Vector2f pos;
	int radius=20;
	int r = 190, g = 50, b = 140;
    float velx=8,vely=8;
    public:
	Ball(){
		pos.x=360;
		pos.y=900;
		ball.setPosition(pos);
		ball.setRadius(radius);
	    ball.setFillColor(sf::Color(r,g,b));
	
	}	
	Ball(int rad){
		radius=rad;
		pos.x=360;
		pos.y=900;
		ball.setPosition(pos);
		ball.setRadius(radius);
	    ball.setFillColor(sf::Color(r,g,b));
	}
	//auto ball movement and collusion
	void move(){
		
	/*	if(ball.getGlobalBounds().intersects(player.get_rec().getGlobalBounds())){
			vely*=-1;
		//	wind.close();
			}else{*/
		if (pos.x >( 700-radius)|| pos.x < 0)
		{
			velx*= -1;
		}
		if (pos.y > (1600-radius)|| pos.y < 0)
		{
			vely*= -1;
		}
		pos.x += velx;
		pos.y += vely;
		ball.setPosition(pos);
		
		}
			//change color
		
	void color(){
		float color1 = 5, color2 = 8, color3 = 11;
		r+=color1;
			g+=color2;
			b+=color3;
			ball.setFillColor(sf::Color(r, g, b));
		
		}
		//get ball position
		sf::Vector2f get_pos(){
		return pos;	
		}
	//render ball on the screen
	void reveal(sf::RenderWindow &wind){
		wind.draw(ball);
	}
	};
int main(int argc, char *argv[])
{
	//create object from Ball class
	Ball ball1(50);
	
	//render the window
sf::RenderWindow window(sf::VideoMode(720,1640),"kags");
window.setFramerateLimit(60);
sf::Clock clock;

while(window.isOpen()){
sf::Event event;
   while(window.pollEvent(event)){
   	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
   		window.close();
   	}else if (event.Closed){
   		window.close();
   	}
   }
   if(clock.getElapsedTime().asMilliseconds() >250){
   	ball1.color();
   	clock.restart();
   }
   ball1.move();
window.clear();
ball1.reveal(window);
window.display();
}
return 0;	
}