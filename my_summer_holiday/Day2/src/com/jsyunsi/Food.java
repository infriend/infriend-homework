package com.jsyunsi;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;

public class Food
{
	public static final int WIDTH = 50;
	public static final int LENGTH = 50;
	private int[] x = new int[6];
	private int[] y = new int[6];
	private static Toolkit tk = Toolkit.getDefaultToolkit();
	private static Image[] images = null;
	static
	{
		images = new Image[]
				{
						tk.getImage(Food.class.getResource("../../image/1.jpg")),
						tk.getImage(Food.class.getResource("../../image/2.jpg")),
						tk.getImage(Food.class.getResource("../../image/3.jpg")),
						tk.getImage(Food.class.getResource("../../image/4.jpg")),
						tk.getImage(Food.class.getResource("../../image/5.jpg")),
						tk.getImage(Food.class.getResource("../../image/6.jpg"))
				};
	}
	public Food()
	{
		for (int i = 0; i < images.length; i++)
		{
			x[i] = (int) (Math.random()*700) + 50;
			y[i] = (int) (Math.random()*500) + 50;
		}
	}
	
	public void draw(Graphics g)
	{
		for (int i = 0; i < images.length; i++)
		{
			g.drawImage(images[i], x[i], y[i], WIDTH, LENGTH, null);
		}
	}
}
