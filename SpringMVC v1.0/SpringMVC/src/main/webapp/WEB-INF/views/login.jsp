<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page session="false"%>
<html>
<head>
<title>Home</title>
<style>
* {
	background-color: gray;
}

table,body {
	text-align:center;
	vertical-align:center;
}
</style>
</head>
<body onload='document.login.j_username.focus();'>
	<h1>Login to Hospital Management System!</h1>
	<h6>${error}</h6>



	<form name="login" action="<c:url value='j_spring_security_check' />"
		method='POST'>
		<table>
			<tr>
				<td>Username</td>
				<td><input type="text" name="j_username" value=''></td>
			</tr>
			<tr>
				<td>Password</td>
				<td><input type="password" name="j_password" value=''></td>
			</tr>
			<tr>
				<td><input name="submit" type="submit" value="submit" /></td>
			</tr>
		</table>
	</form>
</body>
</html>
