<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="house_resource_module.aspx.cs" Inherits="database_course_design.WebForm1" %>

<!DOCTYPE html>
<html lang="en">

  <head>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">
    <link href="https://fonts.googleapis.com/css?family=Roboto:100,300,400,500,700" rel="stylesheet">

    <title>Ramayana - Free Bootstrap 4 CSS Template</title>

    <!-- Bootstrap core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Additional CSS Files -->
    <link rel="stylesheet" href="assets/css/fontawesome.css">
    <link rel="stylesheet" href="assets/css/templatemo-style.css">
    <link rel="stylesheet" href="assets/css/owl.css">

  </head>

<body class="is-preload">

    <form id="form1" runat="server">

    <!-- Wrapper -->
    <div id="wrapper">

      <!-- Main -->
        <div id="main">
          <div class="inner">

            <!-- Header -->
            <header style ="background-color:darkmagenta"  id="header">
              <div class="logo">
                <a href="homepage.aspx">Ramayana</a>
              </div>
            </header>

            <!-- Banner -->

            <!-- Services -->
            <section class="services">
                <div>
                    <asp:Label ID="Label1" runat="server" Text="房号"></asp:Label>
                    <asp:TextBox ID="TextBox1" runat="server" Height="25px" Width="150px"></asp:TextBox>
                    &nbsp;<asp:Label ID="Label2" runat="server" Text="房产证号"></asp:Label>
                    <asp:TextBox ID="TextBox2" runat="server" Height="25px" Width="150px"></asp:TextBox>
                &nbsp;<asp:Label ID="Label3" runat="server" Text="总面积"></asp:Label>
                    <asp:TextBox ID="TextBox3" runat="server" Height="25px" Width="150px"></asp:TextBox>
&nbsp;
                    <asp:Label ID="Label4" runat="server" Text="阳台面积"></asp:Label>
                    <asp:TextBox ID="TextBox4" runat="server" Height="25px" Width="150px"></asp:TextBox>
                &nbsp;
                    <asp:Label ID="Label5" runat="server" Text="级别"></asp:Label>
                    <asp:TextBox ID="TextBox5" runat="server" Height="25px" Width="150px"></asp:TextBox>
                </div>
                <div>
                    <div>
                        <div style="margin-left: 0px">
                            &nbsp;&nbsp;
                        </div>
                        <p>    
                            <asp:Button ID="Button1" runat="server" Height="49px" OnClick="Button1_Click" Text="添加" Width="95px" />
                        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:Button ID="Button2" runat="server" Height="49px" OnClick="Button2_Click" Text="查询" Width="95px" />
                        </p>
                    </div>
                    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="房号" DataSourceID="SqlDataSource1" CellPadding="4" ForeColor="#333333" GridLines="None">
                        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
                        <Columns>
                            <asp:BoundField DataField="房号" HeaderText="房号" ReadOnly="True" SortExpression="房号" />
                            <asp:BoundField DataField="房产证号" HeaderText="房产证号" SortExpression="房产证号" />
                            <asp:BoundField DataField="总面积" HeaderText="总面积" SortExpression="总面积" />
                            <asp:BoundField DataField="阳台面积" HeaderText="阳台面积" SortExpression="阳台面积" />
                            <asp:BoundField DataField="级别" HeaderText="级别" SortExpression="级别" />
                            <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
                        </Columns>
                        <EditRowStyle BackColor="#999999" />
                        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
                        <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
                        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
                        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
                        <SortedAscendingCellStyle BackColor="#E9E7E2" />
                        <SortedAscendingHeaderStyle BackColor="#506C8C" />
                        <SortedDescendingCellStyle BackColor="#FFFDF8" />
                        <SortedDescendingHeaderStyle BackColor="#6F8DAE" />
                    </asp:GridView>
                    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:UHDBConnectionString %>" SelectCommand="SELECT * FROM [房产情况]" ConflictDetection="CompareAllValues" DeleteCommand="DELETE FROM [房产情况] WHERE [房号] = @original_房号 AND [房产证号] = @original_房产证号 AND [总面积] = @original_总面积 AND [阳台面积] = @original_阳台面积 AND (([级别] = @original_级别) OR ([级别] IS NULL AND @original_级别 IS NULL))" InsertCommand="INSERT INTO [房产情况] ([房号], [房产证号], [总面积], [阳台面积], [级别]) VALUES (@房号, @房产证号, @总面积, @阳台面积, @级别)" OldValuesParameterFormatString="original_{0}" UpdateCommand="UPDATE [房产情况] SET [房产证号] = @房产证号, [总面积] = @总面积, [阳台面积] = @阳台面积, [级别] = @级别 WHERE [房号] = @original_房号 AND [房产证号] = @original_房产证号 AND [总面积] = @original_总面积 AND [阳台面积] = @original_阳台面积 AND (([级别] = @original_级别) OR ([级别] IS NULL AND @original_级别 IS NULL))">
                        <DeleteParameters>
                            <asp:Parameter Name="original_房号" Type="String" />
                            <asp:Parameter Name="original_房产证号" Type="String" />
                            <asp:Parameter Name="original_总面积" Type="Int16" />
                            <asp:Parameter Name="original_阳台面积" Type="Int16" />
                            <asp:Parameter Name="original_级别" Type="String" />
                        </DeleteParameters>
                        <InsertParameters>
                            <asp:Parameter Name="房号" Type="String" />
                            <asp:Parameter Name="房产证号" Type="String" />
                            <asp:Parameter Name="总面积" Type="Int16" />
                            <asp:Parameter Name="阳台面积" Type="Int16" />
                            <asp:Parameter Name="级别" Type="String" />
                        </InsertParameters>
                        <UpdateParameters>
                            <asp:Parameter Name="房产证号" Type="String" />
                            <asp:Parameter Name="总面积" Type="Int16" />
                            <asp:Parameter Name="阳台面积" Type="Int16" />
                            <asp:Parameter Name="级别" Type="String" />
                            <asp:Parameter Name="original_房号" Type="String" />
                            <asp:Parameter Name="original_房产证号" Type="String" />
                            <asp:Parameter Name="original_总面积" Type="Int16" />
                            <asp:Parameter Name="original_阳台面积" Type="Int16" />
                            <asp:Parameter Name="original_级别" Type="String" />
                        </UpdateParameters>
                    </asp:SqlDataSource>
                </div>
            </section>
            <div class="tlinks">Collect from <a href="http://www.cssmoban.com/" >建站模板</a></div>

            <!-- Top Image -->

            <!-- Left Image -->

            <!-- Right Image -->

          </div>
        </div>

      <!-- Sidebar -->
        <div id="sidebar">

          <div class="inner">

            <!-- Search Box -->
            <section id="search" class="alt">
                <input type="text" name="search" id="search" placeholder="Search..." />
              </section>
              
            <!-- Menu -->
            <nav id="menu">
              <ul>
                <li><a href="index.html">Homepage</a></li>
                <li><a href="simple_page.html">Simple Page</a></li>
                <li><a href="shortcodes.html">Shortcodes</a></li>
                <li><a href="#">External Link</a></li>
              </ul>
            </nav>

            <!-- Featured Posts -->

            <!-- Footer -->
            <footer id="footer">
            </footer>

          </div>
        </div>

    </div>

  <!-- Scripts -->
  <!-- Bootstrap core JavaScript -->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

    <script src="assets/js/browser.min.js"></script>
    <script src="assets/js/breakpoints.min.js"></script>
    <script src="assets/js/transition.js"></script>
    <script src="assets/js/owl-carousel.js"></script>
    <script src="assets/js/custom.js"></script>
    </form>
</body>


  </body>

</html>





