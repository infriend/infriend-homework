package getbubbles;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Toolkit;

public class Bubble
{
	public static final int WIDTH = 50;
	public static final int LENGTH = 60;
	
	private int[] x = new int[6];
	private int[] y = new int[6];
	
	private char dirs[] = {'W', 'A', 'S', 'D', 'P'};
	private char[] dir = new char[6];
	private int[] action = new int[6];
	
	public int getX(int i)
	{
		return x[i];
	}

	public void setX(int e, int i)
	{
		this.x[i] = e;
	}

	public int getY(int i)
	{
		return y[i];
	}

	public void setY(int e, int i)
	{
		this.y[i] = e;
	}

	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image image = null;
	static
	{
		image = tk.getImage(Bubble.class.getResource("../images/ball.png"));
	}
	
	public Bubble()
	{
		for (int i = 0 ; i < x.length; i++)
		{
			x[i] = (int) (Math.random()*500) + 200;
			y[i] = (int) (Math.random()*500) + 50;
			action[i] = 0;
		}
		
	}
	
	public void draw(Graphics g)
	{
		movebubble();
		for (int i = 0; i < x.length; i++)
		{
			g.drawImage(image, x[i], y[i], WIDTH, LENGTH, null);
		}
		
	}
	
	public void movebubble()
	{
		int randnum;
		for (int i = 0; i < action.length; i++)
		{
			if (action[i] == 0)
			{
				action[i] = (int) (Math.random()*30);
				randnum = (int) (Math.random()*5);
				System.out.println(randnum);
				if(randnum == 5) randnum--;
				dir[i] = dirs[randnum];
				System.out.println(dir[i]);
			}
			else 
			{
				action[i]--;
				switch(dir[i])
				{
				case 'W':
					if(y[i] == 50)
					{
						break;
					}
					else 
					{
						y[i] -= 5;
						break;
					}
				case 'A':
					if(x[i] == 50)
					{
						break;
					}
					else 
					{
						x[i] -= 5;
						break;
					}
				case 'S':
					if(y[i] == 500)
					{
						break;
					}
					else 
					{
						y[i] += 5;
						break;
					}
				case 'D':
					if(x[i] == 700)
					{
						break;
					}
					else 
					{
						x[i] += 5;
						break;
					}
				case 'P':
					break;
				}
			}
		}
	}
	
	
	public Rectangle[] getRect()
	{
		Rectangle rects[] = new Rectangle[6];
		for (int i = 0; i < rects.length; i++)
		{
			rects[i] = new Rectangle(x[i], y[i], WIDTH, LENGTH);
		}
		return rects;
	}
	
	
	
}
