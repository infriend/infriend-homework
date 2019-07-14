package com.jsyunsi;

public class Student extends People
{
	private int score;

	public Student(String name, int age, char sex, int score)
	{
		super(name, age, sex);
		this.score = score;
	}
}
