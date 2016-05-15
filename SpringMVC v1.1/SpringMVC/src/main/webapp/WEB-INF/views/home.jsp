<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page session="false"%>
<html>
<head>
<title>Home</title>
<style>
* {
	background-color: gray;
}

p {
	vertical-align: center;
	text-align: center;
}
</style>
</head>
<body>
	<p>
		<a href="<c:url value='/patients' />">${patients}</a>
	</p>
	<p>
		<a href="<c:url value='/doctors' />">${doctors}</a>
	</p>
	<p>
		<a href="<c:url value='/nurse' />">${nurse}</a>
	</p>
	<p>
		<a href="<c:url value='/wards' />">${wards}</a>
	</p>
	<p></p>
</body>
</html>
