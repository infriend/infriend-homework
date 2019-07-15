package getbubbles;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;

public class Player
{
	public static final int WIDTH = 60;
	public static final int LENGTH = 60;
	
	private int x, y;
	private int speedX = 20, speedY = 20;
	private int score;
	
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image[] image = null;
	
	private boolean bA, bD, bS, bW = false;
	private char dir;
	
	static
	{
		image = new Image[]
				{
						tk.getImage(Player.class.getResource("../images/down.png")),
						tk.getImage(Player.class.getResource("../images/up.png")),
						tk.getImage(Player.class.getResource("../images/left.png")),
						tk.getImage(Player.class.getResource("../images/right.png"))
				};
	}
	
	public int getScore()
	{
		return score;
	}

	public Player()
	{
		x = 100;
		y = 300;
		score = 0;
	}
	
	public void draw(Graphics g)
	{
		g.drawImage(image[0], x, y, WIDTH, LENGTH, null);
		switch(dir)
		{
		case 'W':
			g.drawImage(image[1], x, y, WIDTH, LENGTH, null);
			break;
		case 'S':
			g.drawImage(image[0], x, y, WIDTH, LENGTH, null);
			break;
		case 'A':
			g.drawImage(image[2], x, y, WIDTH, LENGTH, null);
			break;
		case 'D':
			g.drawImage(image[3], x, y, WIDTH, LENGTH, null);
			break;
		case 'P':
			g.drawImage(image[0], x, y, WIDTH, LENGTH, null);
			break;
		}
		move();
		
	}
	public void move()
	{
		switch(dir)
		{
		case 'W':
			y -= speedY;
			break;
		case 'A':
			x -= speedX;
			break;
		case 'S':
			y += speedY;
			break;
		case 'D':
			x += speedX;
			break;
		case 'P':
			break;
		}
	}
	
	private void decideDirection()
	{
		// TODO Auto-generated method stub
		if (bA && !bS && !bD && !bW)
		{
			dir = 'A';			
		}
		else if (bS && !bA && !bD && !bW)
		{
			dir = 'S';
		}
		else if (bD && !bA && !bS && !bW)
		{
			dir = 'D';
		}
		else if (bW && !bS && !bD && !bD)
		{
			dir = 'W';
		}
		else if (!bW && !bS && !bD && !bD)
		{
			dir = 'P';
		}
	}
	
	public void keyPressed(KeyEvent e)
	{
		int keycode = e.getKeyCode();
		switch(keycode)
		{
		case KeyEvent.VK_A: 
			System.out.println("A");
			bA = true;
			break;
		case KeyEvent.VK_D:
			System.out.println("D");
			bD = true;
			break;
		case KeyEvent.VK_S:
			System.out.println("S");
			bS = true;
			break;
		case KeyEvent.VK_W:
			System.out.println("W");
			bW = true;
			break;
		}
		decideDirection();
	}
	

	public void keyReleased(KeyEvent e)
	{
		int keycode = e.getKeyCode();
		switch(keycode)
		{
		case KeyEvent.VK_A: 
			System.out.println("A");
			bA = false;
			break;
		case KeyEvent.VK_D:
			System.out.println("D");
			bD = false;
			break;
		case KeyEvent.VK_S:
			System.out.println("S");
			bS = false;
			break;
		case KeyEvent.VK_W:
			System.out.println("W");
			bW = false;
			break;
		}
		decideDirection();
	}
	
	public Rectangle getRect()
	{
		return new Rectangle(x, y, WIDTH, LENGTH);
	}
	
	public void touch(Bubble bubble)
	{
		Rectangle[] rects = bubble.getRect();
		for (int i = 0; i < rects.length; i++)
		{
			if(this.getRect().intersects(rects[i]))
			{
				bubble.setX(-100, i);
				bubble.setY(-100, i);
				score += 10;
				System.out.println("touch");
			}
		}
	}
	
	
}
