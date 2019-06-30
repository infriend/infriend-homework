<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="login.aspx.cs" Inherits="database_course_design.homepage" %>

<!DOCTYPE HTML>
<html>
<head>
<title>Purple_loginform Website Template | Home :: w3layouts</title>
<link href="css/style.css" rel="stylesheet" type="text/css" media="all" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 
<!-- -->
<script>var __links = document.querySelectorAll('a');function __linkClick(e) { parent.window.postMessage(this.href, '*');} ;for (var i = 0, l = __links.length; i < l; i++) {if ( __links[i].getAttribute('data-t') == '_blank' ) { __links[i].addEventListener('click', __linkClick, false);}}</script>
<script src="js/jquery.min.js"></script>
<script>$(document).ready(function(c) {
	$('.alert-close').on('click', function(c){
		$('.message').fadeOut('slow', function(c){
	  		$('.message').remove();
		});
	});	  
});
</script>
</head>
<body>
<!-- contact-form -->	
<div class="message warning">
<div class="inset">
	<div class="login-head">
		<h1>&nbsp;登陆</h1>
		 <div class="alert-close"> </div> 			
	</div>
		<form id="form1" runat="server">
			<li>
				<a href="#" class=" icon user"></a>
                <asp:TextBox ID="TextBox1" runat="server" BorderStyle="Double" OnTextChanged="TextBox1_TextChanged" Width="169px" Height="16px"></asp:TextBox>
            </li><li>
				&nbsp;<a href="#" class="icon lock"></a>
               <asp:TextBox ID="TextBox2" runat="server" BorderStyle="Double" Height="16px" Width="169px"></asp:TextBox>
           </li>
				<div class="clear"> </div>
                <asp:Button ID="Button1" runat="server" Text="LOGIN" OnClick="Button1_Click" />
                <br />
			<div class="clear"> 
                </div>
			<div class="submit">
&nbsp;<h4>
                    <asp:Label ID="Label1" runat="server" Text="用户名或密码错误"></asp:Label>
                </h4>
						  <div class="clear">  </div>	
			</div>
				
		</form>
		</div>					
	</div>
	</div>
	
</body>
</html>
