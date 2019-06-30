using database_course_design.houseTableAdapters;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace database_course_design
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        

        protected void Button1_Click(object sender, EventArgs e)
        {
            string 房号 = Convert.ToString(TextBox1.Text.Trim());
            string 房产证号 = Convert.ToString(TextBox2.Text.Trim());
            short 总面积 = Convert.ToInt16(TextBox3.Text.Trim());
            short 阳台面积 = Convert.ToInt16(TextBox4.Text.Trim());
            string 级别 = Convert.ToString(TextBox5.Text.Trim());
            房产情况TableAdapter adapter = new 房产情况TableAdapter();
            adapter.Insert_house_detail(房号, 房产证号, 总面积, 阳台面积, 级别);

        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            string 房号 = Convert.ToString(TextBox1.Text.Trim());
            string 房产证号 = Convert.ToString(TextBox2.Text.Trim());
            short 总面积 = Convert.ToInt16(TextBox3.Text.Trim());
            short 阳台面积 = Convert.ToInt16(TextBox4.Text.Trim());
            string 级别 = Convert.ToString(TextBox5.Text.Trim());
            房产情况TableAdapter adapter = new 房产情况TableAdapter();

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}