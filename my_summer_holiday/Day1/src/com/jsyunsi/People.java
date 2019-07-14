package com.jsyunsi;

public class People
{
	//无参构造
	public People()
	{
		System.out.println("无参构造");
	}
	//有参构造
	public People(String name, int age, char sex) {
		super();
		this.name = name;
		this.age = age;
		this.sex = sex;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public char getSex() {
		return sex;
	}
	public void setSex(char sex) {
		this.sex = sex;
	}
		//定义类的属性
		private String name;
		private int age;
		private char sex;
	////定义类的行为（方法）
		public void eat()
		{
			System.out.println("恰饭");
		}
		public void sleep(String where)
		{
			System.out.println("我在" + where + "睡觉！");
		}
		public int playGame(int n)
		{
			System.out.println("我一天打" + n + "次游戏");
			return n;
		}

}
