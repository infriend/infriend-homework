package com.jsyunsi;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class demo extends Frame
{
	public static final int FRAME_WIDTH = 800;
	public static final int FRAME_LENGTH = 600;
	
	
	Toolkit tk = Toolkit.getDefaultToolkit();
	Dimension screensize = tk.getScreenSize();
	
	int screenWidth = screensize.width;
	int screenLength = screensize.height;
	
	int []coordx = new int[60];
	int []coordy = new int[60];
	
	Image image = null;
	
	Food food = new Food();
	
	public void update(Graphics g)
	{
		image = this.createImage(FRAME_WIDTH, FRAME_LENGTH);
		Graphics gps = image.getGraphics();
		framePaint(gps);
		g.drawImage(image, 0, 0, null);
	}
	
	
	private void framePaint(Graphics g)
	{
		// TODO Auto-generated method stub
		food.draw(g);
	}


	public demo()
	{
		this.setBackground(Color.gray);
		this.setSize(FRAME_WIDTH, FRAME_LENGTH);
		this.setVisible(true);
		this.setResizable(false);
		this.addWindowListener(new WindowAdapter()
				{
					public void windowClosing(WindowEvent e)
					{
						System.exit(0);
					}
				});
		this.setLocation(screenWidth/2 - FRAME_WIDTH, screenLength/2 - FRAME_LENGTH);
		new Thread(new PaintThread()).start();
	}
	
	private class PaintThread implements Runnable
	{
		public void run()
		{
			while(true)
			{
				repaint();
				try 
				{
					Thread.sleep(50);
				}
				catch (InterruptedException e) 
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		new demo();
	}

}
