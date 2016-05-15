package com.imc.spring.dao;

import java.util.List;

import org.hibernate.Criteria;
import org.hibernate.SessionFactory;
import org.hibernate.criterion.Order;
import org.hibernate.criterion.Restrictions;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.imc.spring.model.Ward;

@Repository
// DAO layer
public class WardDaoImpl implements WardDao {

	@Autowired // dependency injection
	private SessionFactory sessionFactory;
	// sessionFactory(thread-safe) for singleton default pattern for Spring

	public void addWard(Ward ward) {
		sessionFactory.getCurrentSession().save(ward);
	}

	public void deleteWard(long Id) {
		Criteria criteria = sessionFactory.getCurrentSession().createCriteria(Ward.class);
		criteria.add(Restrictions.eq("id", Id));
		Ward ward = (Ward) criteria.uniqueResult();
		sessionFactory.getCurrentSession().delete(ward);
	}

	public Ward getWard(long Id) {
		return (Ward) sessionFactory.getCurrentSession().get(Ward.class, Id);
	}

	@SuppressWarnings("unchecked")
	public List<Ward> getWards() {
		Criteria criteria = sessionFactory.getCurrentSession().createCriteria(Ward.class)
				.addOrder(Order.asc("id"));
		List<Ward> wards = (List<Ward>) criteria.list();
		return wards;
	}

	public void updateWard(Ward ward) {
		Ward entity = getWard(ward.getId());
		if (entity != null) {
			entity.setId(ward.getId());
			entity.setFirstName(ward.getFirstName());
			entity.setLastName(ward.getLastName());
			entity.setPhone(ward.getPhone());
			entity.setEmail(ward.getEmail());
			entity.setSalary(ward.getSalary());
			entity.setAddress(ward.getAddress());
		}
		sessionFactory.getCurrentSession().update(entity);
	}
}
