using database_course_design.DataSet1TableAdapters;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace database_course_design
{
    public partial class homepage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {
            string username = Convert.ToString(TextBox1.Text.Trim());
            string passwd = Convert.ToString(TextBox2.Text.Trim());
            userdataTableAdapter adapter = new userdataTableAdapter();
            var data = adapter.GetDataBynameandpasswd(username, passwd);
            if (data.Rows.Count<1)
            {
                Label1.Visible = true;
            }
            else
            {
                var result = data.Single();
                if (result.authority == 0)
                {

                }
                else
                {

                }
            }
        }
    }
}