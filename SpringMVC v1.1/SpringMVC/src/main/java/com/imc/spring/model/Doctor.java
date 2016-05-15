package com.imc.spring.model;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "DOCTOR")
public class Doctor implements Serializable {
	private static final long serialVersionUID = 128342342636L;
	// in case i put it on web
	@Id
	@Column(name = "doctor_id")
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;

	@NotEmpty
	@Column(name = "first_name", nullable = false)
	private String firstName;

	@NotEmpty
	@Column(name = "last_name", nullable = false)
	private String lastName;

	@NotEmpty
	@Column(name = "phone", nullable = false)
	private String phone;

	@NotEmpty
	@Column(name = "email", nullable = false)
	private String email;

	@NotEmpty
	@OneToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "address", nullable = false)
	private Address address;

	@NotEmpty
	@Column(name = "doc_type", nullable = false)
	private String docType;

	@NotEmpty
	@Column(name = "salary", nullable = false)
	private BigDecimal salary;

	@NotEmpty
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "department_id", nullable = false)
	private Department department;

	@NotEmpty
	@OneToMany(fetch = FetchType.LAZY, mappedBy = "doctor")
	// mappedBy to know the owner in this bidirectional relationship
	private Set<Patient> patients;
	// because i use a collection i should override hashcode and equals methods
	// because there's a chance to instantiate 2 diff objects representing the
	// same row in db
	// in hibernate i should call Hibernate.initialize(doctor.getPatients());

	public Doctor() {
	}
	// empty constructor coz hibernate

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public Address getAddress() {
		return address;
	}

	public void setAddress(Address address) {
		this.address = address;
	}

	public String getDocType() {
		return docType;
	}

	public void setDocType(String docType) {
		this.docType = docType;
	}

	public BigDecimal getSalary() {
		return salary;
	}

	public void setSalary(BigDecimal salary) {
		this.salary = salary;
	}

	public Set<Patient> getPatients() {
		return patients;
	}

	public void setPatients(Set<Patient> patients) {
		this.patients = patients;
	}

	public Department getDepartment() {
		return department;
	}

	public void setDepartment(Department department) {
		this.department = department;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || !(o instanceof Doctor))
			return false;
		Doctor doc = (Doctor) o;
		if (id == null)
			return false;
		return id.equals(doc.getId());
	}

	@Override
	public int hashCode() {
		if (id != null)
			return 31 * id.hashCode();
		return 31 * super.hashCode();
	}
}
