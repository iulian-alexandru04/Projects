<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<html>

<head>
</head>

<body>
	<div class="generic-container">
		<div class="panel panel-default">
			<!-- Default panel contents -->
			<div class="panel-heading">
				<span class="lead">List of Users </span>
			</div>
			<table class="table table-hover">
				<thead>
					<tr>
						<th>First Name</th>
						<th>Last Name</th>
						<th>Email</th>
						<th>Phone</th>
						<th>Salary</th>

						<th width="100"></th>
						<th width="100"></th>
					</tr>
				</thead>
				<tbody>
					<c:forEach items="${wards}" var="ward">
						<tr>
							<td>${ward.firstName}</td>
							<td>${ward.lastName}</td>
							<td>${ward.email}</td>
							<td>${ward.phone}</td>
							<td>${ward.salary}</td>
							<td><a href="<c:url value='/edit-user-${ward.id}' />"
								class="btn btn-success 
 
custom-width">edit</a></td>
							<td><a href="<c:url value='/delete-user-${ward.id}' />"
								class="btn btn-danger 
 
custom-width">delete</a></td>
						</tr>
					</c:forEach>
				</tbody>
			</table>
		</div>
		<div class="well">
			<a href="<c:url value='/newward' />">Add New Ward</a>
		</div>
	</div>
</body>
</html>