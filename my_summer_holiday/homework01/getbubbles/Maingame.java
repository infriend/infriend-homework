package getbubbles;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Maingame extends Frame implements ActionListener
{
	public static void main(String[] args)
	{
		new Maingame();
	}
	
	public static final int FRAME_WIDTH = 800;
	public static final int FRAME_LENGTH = 600;
	
	Toolkit tk = Toolkit.getDefaultToolkit();
	Dimension screensize = tk.getScreenSize();
	
	int screenWidth = screensize.width;
	int screenLength = screensize.height;
	
	Image image = null;
	
	MenuBar jmb = null;
	Menu jm = null;
	MenuItem jm1 = null;
	MenuItem jm2 = null;
	
	Player player = new Player();
	Bubble bubble = new Bubble();
	
	private boolean printable = true;
	
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
		g.drawString("SCORE: " + player.getScore(), 300, 300);
		player.draw(g);
		bubble.draw(g);
		player.touch(bubble);
		
		
	}


	private class KeyMonitor extends KeyAdapter
	{
		public void keyPressed(KeyEvent e)
		{
			player.keyPressed(e);
		}
		public void keyReleased(KeyEvent e)
		{
			player.keyReleased(e);
		}
	}


	public Maingame()
	{
		//MENU PART
		jmb = new MenuBar();
		jm = new Menu("STOP/CONTINUE");
		
		jm1 = new MenuItem("STOP");
		jm1.addActionListener(this);
		jm1.setActionCommand("stop");
		
		jm2 = new MenuItem("CONTINUE");
		jm2.addActionListener(this);
		jm2.setActionCommand("continue");
		
		jmb.add(jm);
		jm.add(jm1);
		jm.add(jm2);
		
		this.setMenuBar(jmb);
		
		
		this.setBackground(Color.white);
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
		this.addKeyListener(new KeyMonitor());
		
		this.setLocation(screenWidth/2 - FRAME_WIDTH, screenLength/2 - FRAME_LENGTH);
		
		new Thread(new PaintThread()).start();
	}
	
	private class PaintThread implements Runnable
	{
		public void run()
		{
			while(printable)
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
	
	@Override
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand().equals("stop"))
		{
			System.out.println("STOP");
			printable = false;
		}
		if(e.getActionCommand().equals("continue"))
		{
			System.out.println("CONTINUE");
			if(!printable)
			{
				printable = true;
				new Thread(new PaintThread()).start();
			}
		}
		
	}
	
	
	
	
	
}
