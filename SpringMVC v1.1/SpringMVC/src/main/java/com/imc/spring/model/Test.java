package com.imc.spring.model;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "TEST")
public class Test implements Serializable {
	private static final long serialVersionUID = 12093120L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "test_id", nullable = false)
	private Long id;

	@NotEmpty
	@Column(name = "test_name", nullable = false)
	private String testName;

	@NotEmpty
	@Column(name = "test_date", nullable = false)
	private Date testDate;

	@NotEmpty
	@Column(name = "fee", nullable = false)
	private BigDecimal fee;

	public Test() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getTestName() {
		return testName;
	}

	public void setTestName(String testName) {
		this.testName = testName;
	}

	public Date getTestDate() {
		return testDate;
	}

	public void setTestDate(Date testDate) {
		this.testDate = testDate;
	}

	public BigDecimal getFee() {
		return fee;
	}

	public void setFee(BigDecimal fee) {
		this.fee = fee;
	}

}
