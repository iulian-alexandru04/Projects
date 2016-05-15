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
@Table(name = "MEDICINE")
public class Medicine implements Serializable {
	private static final long serialVersionUID = 234093284L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "medicine_id", nullable = false)
	private Long id;

	@NotEmpty
	@Column(name = "medicine_name", nullable = false)
	private String medicineName;

	@NotEmpty
	@Column(name = "company", nullable = false)
	private String company;

	@NotEmpty
	@Column(name = "start_date", nullable = false)
	private Date startDate;

	@NotEmpty
	@Column(name = "end_date", nullable = false)
	private Date endDate;

	@NotEmpty
	@Column(name = "price", nullable = false)
	private BigDecimal price;

	public Medicine() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getMedicineName() {
		return medicineName;
	}

	public void setMedicineName(String medicineName) {
		this.medicineName = medicineName;
	}

	public String getCompany() {
		return company;
	}

	public void setCompany(String company) {
		this.company = company;
	}

	public Date getStartDate() {
		return startDate;
	}

	public void setStartDate(Date startDate) {
		this.startDate = startDate;
	}

	public Date getEndDate() {
		return endDate;
	}

	public void setEndDate(Date endDate) {
		this.endDate = endDate;
	}

	public BigDecimal getPrice() {
		return price;
	}

	public void setPrice(BigDecimal price) {
		this.price = price;
	}
}
