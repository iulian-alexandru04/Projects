package com.imc.spring.model;

import java.io.Serializable;
import java.math.BigDecimal;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "BILL")
public class Bill implements Serializable {
	private static final long serialVersionUID = 149324820L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "bill_id", nullable = false)
	private Long id;

	@NotEmpty
	@Column(name = "bill_purpose", nullable = false)
	private String billPurpose;

	@NotEmpty
	@Column(name = "total_bill", nullable = false)
	private BigDecimal totalBill;

	public Bill() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getBillPurpose() {
		return billPurpose;
	}

	public void setBillPurpose(String billPurpose) {
		this.billPurpose = billPurpose;
	}

	public BigDecimal getTotalBill() {
		return totalBill;
	}

	public void setTotalBill(BigDecimal totalBill) {
		this.totalBill = totalBill;
	}

}
