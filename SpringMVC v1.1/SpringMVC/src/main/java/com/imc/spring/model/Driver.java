package com.imc.spring.model;

import java.io.Serializable;
import java.math.BigDecimal;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "DRIVER")
public class Driver implements Serializable {
	private static final long serialVersionUID = 234280948205L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "driver_id", nullable = false)
	private Long id;

	@NotEmpty
	@Column(name = "shift", nullable = false)
	private Integer shift;

	@NotEmpty
	@Column(name = "first_name", nullable = false)
	private String fristName;

	@NotEmpty
	@Column(name = "last_name", nullable = false)
	private String lastName;

	@NotEmpty
	@OneToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "address", nullable = false)
	private Address address;

	@NotEmpty
	@Column(name = "phone", nullable = false)
	private String phone;

	@NotEmpty
	@Column(name = "email", nullable = false)
	private String email;

	@NotEmpty
	@Column(name = "salary", nullable = false)
	private BigDecimal salary;

	@NotEmpty
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "ambulance_id", nullable = false)
	private Ambulance ambulance;

	public Driver() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public Integer getShift() {
		return shift;
	}

	public void setShift(Integer shift) {
		this.shift = shift;
	}

	public String getFristName() {
		return fristName;
	}

	public void setFristName(String fristName) {
		this.fristName = fristName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public Address getAddress() {
		return address;
	}

	public void setAddress(Address address) {
		this.address = address;
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

	public BigDecimal getSalary() {
		return salary;
	}

	public void setSalary(BigDecimal salary) {
		this.salary = salary;
	}

	public Ambulance getAmbulance() {
		return ambulance;
	}

	public void setAmbulance(Ambulance ambulance) {
		this.ambulance = ambulance;
	}
}
